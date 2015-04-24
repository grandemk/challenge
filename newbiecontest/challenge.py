class Challenge(object):
    def solve_chall(self):
        pass

    def verify_chall_solved(self):
        pass

    def print_soluce(self):
        pass

class Programmation(Challenge):
    def solve_chall(self):
        pass

    def verify_chall_solved(self, soluce):
        return soluce.find("Bravo") != -1

    def print_soluce(self, soluce):
        if self.verify_chall_solved(soluce.text):
            print("Solved it :) Here is the answer:")
        else:
            print("Something went terribly wrong ! Got this:")

        print(soluce.text)



