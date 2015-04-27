import re
import traceback
import sys
from connection import NewbieContestConnection
from challenge import Programmation
from utils import trace
from exprtree import *
from exprparser import *


class EquationChall(Programmation):
    def __init__(self, trace_level):
        self.connection = NewbieContestConnection(trace_level)
        self.chall_url = "{}/prog4.php".format(self.connection.base_url)
        self.verif_url = "{}/verifpr4.php".format(self.connection.base_url)
        self.equation_regex = re.compile("(.+) est")
        self.pr_debug = trace(trace_level)
        self.trace_level = trace_level

    def get_equation(self):
        r = self.connection.get(self.chall_url)
        result = self.equation_regex.search(r.text)
        if result:
            result = result.group(1)
        return result

    def solve_chall(self):
        equation = self.get_equation()
        lexer = EquationLexer(self.trace_level)
        tokens = lexer.create_tokens(equation)
        parser = EquationLL1Parser(EquationBuilder(), tokens)
        exprtree = parser.parse()
        calculator = CalculatorVisitor()
        printer = PrinterVisitor()
        res = exprtree.accept(printer)
        self.pr_debug(res,3)
        res = int(exprtree.accept(calculator))
        self.pr_debug(res,3)
        soluce = self.connection.valid(self.verif_url, res)
        return soluce

if "__main__" == __name__:
    e = EquationChall(3)
    soluce = e.solve_chall()
    e.print_soluce(soluce)

