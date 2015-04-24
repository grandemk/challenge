#!/usr/bin/env python
from renvoi import Renvoi
import argparse


class ChallengeSolver(object):
    def __init__(self, trace_level):
        self.challs = {"Renvoi"}
        self.trace_level = trace_level

    def print_list_challs(self):
        for chall in self.challs:
            print chall

    def solve_chall(self, chall_name):
        if not chall_name in self.challs:
            print("I don't know this chall\n")
            return
        if chall_name == "Renvoi":
            chall = Renvoi(self.trace_level)

        soluce = chall.solve_chall()
        chall.print_soluce(soluce)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Challenge Solver")
    parser.add_argument('--verbose', default=1, type=int, help='set the verbosity. 0 is the lowest')
    parser.add_argument('--name', help='name of the challenge you want to solve')
    parser.add_argument('--list', action='store_true', help='print a list of the challenges')
    args = parser.parse_args()

    trace_level = args.verbose
    chall_name = args.name
    need_list = args.list

    solver = ChallengeSolver(trace_level)
    if need_list:
        solver.print_list_challs()
    else:
        if not chall_name:
            parser.print_help()
        else:
            solver.solve_chall(chall_name)



