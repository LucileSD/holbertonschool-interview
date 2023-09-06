#!/usr/bin/python3
"""
    function prime game
"""


def isWinner(x, nums):
    """
        function to know who wins at prime game
        args:
            x: the number of rounds
            nums: an array of n
        return:
            MAria or Ben wins
    """
    maria = 0
    ben = 0
    for round in range(0, x):
        nb_of_prime = 0
        limit = nums[round]
        for num in range(2, limit + 1):
            if num == 2 or num == 3:
                nb_of_prime += 1
            for modulo in range(2, int(num / 2) + 1):
                if num % modulo != 0:
                    nb_of_prime += 1
        if nb_of_prime % 2 == 0:
            ben += 1
        else:
            maria += 1
    if maria > ben:
        return 'Maria'
    else:
        return 'Ben'
