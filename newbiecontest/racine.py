import re
import sys
from connection import NewbieContestConnection
from challenge import Programmation

class Racine(Programmation):
    def __init__(self, trace_level):
        self.connection = NewbieContestConnection(trace_level)
        self.a_url = "{}/prog3_1.php".format(self.connection.base_url)
        self.b_url = "{}/prog3_2.php".format(self.connection.base_url)
        self.verif_url = "{}/verifpr1.php".format(self.connection.base_url)
        self.number_regex = re.compile("\d+")

    def get_number(self, url):
        r = self.connection.get(self.url)

        result = self.number_regex.search(r.text)
        if result:
            result = result.group(0)
        return result

    def get_numbers(self):
        a = get_number(self.a_url);
        b = get_number(self.b_url);
        print a,b

if "__main__" == __name__:
    racine = Racine(3)
    racine.get_numbers()

