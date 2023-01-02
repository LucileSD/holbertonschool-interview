#!/usr/bin/python3
"""a method that calculates the fewest number of operations needed to result
   in exactly n H characters in the file"""


def minOperations(n):
    """
        calculates the fewest number of operations
        args:
            n: the number of H desires in the file
        return:
            the number of operations needed to have the number of H
    """
    nbOperation = 0
    nbOfPass = 2
    if n < 1:
        return 0
    while n > 1:
        if n % nbOfPass == 0:
            n = n / nbOfPass
            nbOperation += nbOfPass
        else:
            nbOfPass += 1
    return nbOperation
