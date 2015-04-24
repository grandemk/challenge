import re
import sys
from connection import NewbieContestConnection
from challenge import Programmation

class Renvoi(Programmation):
    def __init__(self, trace_level):
        self.connection = NewbieContestConnection(trace_level)
        self.chall_url = "{}/prog1.php".format(self.connection.base_url)
        self.verif_url = "{}/verifpr1.php".format(self.connection.base_url)
        self.number_regex = re.compile("\d+")

    def get_number(self):
        r = self.connection.get(self.chall_url)

        result = self.number_regex.search(r.text)
        if result:
            result = result.group(0)
        return result

    def valid_number(self, number):
        response_params = {"solution":number}
        r = self.connection.get(self.verif_url, params=response_params)
        return r

    def solve_chall(self):
        result = self.get_number()
        if result is None:
            print("Couldn't parse the number in the http response")
            sys.exit(1)
        soluce = self.valid_number(result)
        return soluce

    def verify_chall_solved(self, soluce):
        return soluce.find("Bravo") != -1

if "__main__" == __name__:
    renvoi = Renvoi(3)
    soluce = renvoi.solve_chall()
    renvoi.print_soluce(soluce)

