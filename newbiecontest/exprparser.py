from exprtree import *
from utils import trace
import re
import sys

class ParsingException(Exception):
    pass

class LexerException(Exception):
    pass

# only support func with one arg for now

# type:
# +, *, INT, FUNC, POW
# value:
# 55, sqrt, etc., operators don't need value

class Token(object):
    def __init__(self, type, value=None):
        self.type = type
        self.value = value

    def __str__(self):
        if self.type == ')':
            type = "RPAR"
        elif self.type == '(':
            type = "LPAR"
        else:
            type = self.type
        if self.value is None:
            s = "{}".format(type)
        else:
            s = "{}:{}".format(type, self.value)
        return s

class EquationLexer(object):
    def __init__(self, trace_level=3):
        self.pr_debug = trace(trace_level)
        self.tokens = list()
        self.racine = re.compile("racine")
        self.power2 = re.compile("&sup2;")
        self.plus = re.compile("\+")
        self.times = re.compile("\*")
        self.parleft = re.compile("\(")
        self.parright = re.compile("\)")
        self.number = re.compile("\d+")
        self.blank = re.compile("[ \t\n]+")

    def create_tokens(self, equation):
        while equation:
            blank = self.blank.match(equation)
            if blank:
                equation = equation[len(blank.group(0)):]

            result = self.racine.match(equation)
            if result:
                tok = Token("FUNC", "sqrt")
                self.tokens.append(tok)
                equation = equation[len(result.group(0)):]
                continue
            result = self.plus.match(equation)
            if result:
                tok = Token("+")
                self.tokens.append(tok)
                equation = equation[len(result.group(0)):]
                continue
            result = self.times.match(equation)
            if result:
                tok = Token("*")
                self.tokens.append(tok)
                equation = equation[len(result.group(0)):]
                continue
            result = self.parleft.match(equation)
            if result:
                tok = Token("(")
                self.tokens.append(tok)
                equation = equation[len(result.group(0)):]
                continue
            result = self.parright.match(equation)
            if result:
                tok = Token(")")
                self.tokens.append(tok)
                equation = equation[len(result.group(0)):]
                continue
            result = self.power2.match(equation)
            if result:
                tok = Token("POW")
                self.tokens.append(tok)
                tok = Token("INT", "2")
                self.tokens.append(tok)
                equation = equation[len(result.group(0)):]
                continue
            result = self.number.match(equation)
            if result:
                tok = Token("INT", result.group(0))
                self.tokens.append(tok)
                equation = equation[len(result.group(0)):]
                continue
            raise LexerException("Couldn't generate token for {}".format(equation))
        # signal the end
        self.tokens.append(Token("$"))
        return self.tokens

class EquationLL1Parser(object):
    def __init__(self, builder, tokens):
        self.builder = builder
        self.tokens = tokens

    def E(self):
        v1 = self.F()
        return self.E2(v1)

    def E2(self, v1):
        if self.tokens[0].type == "+":
            self.tokens.pop(0)
            v2 = self.F()
            v3 = self.builder.createPlus(v1, v2)
            return self.E2(v3)
        else:
            return v1

    def F2(self, v1):
        if self.tokens[0].type == "*":
            self.tokens.pop(0)
            v2 = self.T()
            v3 = self.builder.createMult(v1, v2)
            return self.F2(v3)
        else:
            return v1

    def F(self):
        v1 = self.T()
        return self.F2(v1)

    def T(self):
        v1 = self.FUNC()
        if self.tokens[0].type == "POW":
            self.tokens.pop(0)
            v2 = self.T();
            return self.builder.createPow(v1, v2)
        else:
            return v1

    def FUNC(self):
        if self.tokens[0].type == "FUNC":
            self.tokens.pop(0)
            if self.tokens[0].type == "(":
                self.tokens.pop(0)
                v1 = self.E()
                if self.tokens[0].type == ")":
                    self.tokens.pop(0)
                    return self.builder.createSqrt(v1, self.builder.createNumber(Token("INT",2)))
                raise ParsingException("no matching ) in FUNC")
            else:
                raise ParsingException("no ( after FUNC")
        else:
            return self.H()

    def H(self):
        if self.tokens[0].type == "INT":
            o = self.tokens.pop(0)
            return self.builder.createNumber(o)
        if self.tokens[0].type == "(":
            self.tokens.pop(0)
            v1 = self.E()
            if self.tokens[0].type == ")":
                self.tokens.pop(0)
                return v1
        s = ""
        for i in self.tokens:
            s = "{} ({})".format(s, i)
        raise ParsingException("in H: {}".format(s))

    def parse(self):
        e = self.E()
        if self.tokens[0].type == "$":
            print("Parsing succeeded\n")
            return e
        raise ParsingException("Not in the grammar")


class EquationOnlyParser(object):
    def __init__(self, builder):
        self.builder = builder
        eq="racine\((\d+)\)\*(\d+)&sup2;\+(\d+)"
        self.recognize_equation = re.compile(eq)

    def parse(self, equation):
        tokens = self.recognize_equation.match(equation)
        res = self.builder.createPlus(self.builder.createMult(self.builder.createSqrt(self.builder.createNumber(tokens.group(1)), self.builder.createNumber(2)), self.builder.createPow(self.builder.createNumber(tokens.group(2)), self.builder.createNumber(2))),self.builder.createNumber(tokens.group(3)))
        return res

class AbstractEquationBuilder(object):
    def __init__(self):
        pass
    def createSqrt(self, left , right):
        pass
    def createNumber(self, value):
        pass
    def createPow(self, left, right):
        pass
    def createMult(self, left, right):
        pass
    def createPlus(self, left, right):
        pass

class EquationBuilder(AbstractEquationBuilder):
    def __init__(self):
        pass
    def createSqrt(self, left, right):
        return SquareRoot(left, right)
    def createNumber(self, value):
        return Number(value)
    def createPow(self, left, right):
        return Power(left, right)
    def createMult(self, left, right):
        return Mul(left, right)
    def createPlus(self, left, right):
        return Plus(left, right)


if __name__ == "__main__":
    e = EquationLexer()
    if len(sys.argv) < 2:
        print("usage: python {} equation".format(sys.argv[0]))
        sys.exit(1)
    eq = sys.argv[1]

    builder = EquationBuilder()
    tokens = e.create_tokens(eq)
    s = ""
    for i in tokens:
        s = "{} ({})".format(s, i)
    print(s)
    p = EquationLL1Parser(builder, tokens)
    tree = p.parse()
    v = PrinterVisitor()
    v2 = CalculatorVisitor()
    print(tree.accept(v))
    print(tree.accept(v2))

