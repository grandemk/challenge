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

    def verify_chall_solved(self):
        pass

    def print_soluce(self, soluce):
        if self.verify_chall_solved(soluce.text):
            print("Solved it :) Here is the answer:")
        else:
            print("Something seems to have went wrong, here is what we got:")

        print(soluce.text)



