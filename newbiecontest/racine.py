import re
import sys
from connection import NewbieContestConnection
from challenge import Programmation
from math import sqrt

class RacineChall(Programmation):
    def __init__(self, trace_level):
        self.connection = NewbieContestConnection(trace_level)
        self.a_url = "{}/prog3_1.php".format(self.connection.base_url)
        self.b_url = "{}/prog3_2.php".format(self.connection.base_url)
        self.verif_url = "{}/verifpr3.php".format(self.connection.base_url)
        self.number_regex = re.compile("\d+")
        self.y=0

    def get_number(self, url):
        r = self.connection.get(url)

        result = self.number_regex.search(r.text)
        if result:
            result = result.group(0)
        return int(result)

    def get_numbers(self):
        a = self.get_number(self.a_url);
        b = self.get_number(self.b_url);
        return a,b

    def valid_equation(self, y):
        return self.connection.valid(self.verif_url, y)

    def solve_chall(self):
        a,b = self.get_numbers()
        y = int(sqrt(a) * b)
        soluce = self.valid_equation(y)
        return soluce


if "__main__" == __name__:
    racine = RacineChall(3)
    soluce = racine.solve_chall()
    racine.print_soluce(soluce)

