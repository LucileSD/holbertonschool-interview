#!/usr/bin/python3
"""The N queens puzzle"""
import sys


def nqueens(N):
    """resolve nqueens problem with backtrack"""
    def backtrack(row, columns, left_diag, right_diag):
        """come back on itself if the solution is not good"""
        if row == N:
            print([[r, c] for r, c in enumerate(columns)])
        else:
            for col in range(N):
                if col not in columns and row-col not in left_diag\
                   and row+col not in right_diag:
                    columns.append(col)
                    left_diag.add(row-col)
                    right_diag.add(row+col)
                    backtrack(row+1, columns, left_diag, right_diag)
                    columns.pop()
                    left_diag.remove(row-col)
                    right_diag.remove(row+col)

    backtrack(0, [], set(), set())


if (len(sys.argv) != 2):
    print("Usage: nqueens N")
    sys.exit(1)
try:
    N = int(sys.argv[1])
except ValueError:
    print("N must be a number")
    sys.exit(1)
if N < 4:
    print("N must be at least 4")
    sys.exit(1)

nqueens(N)
