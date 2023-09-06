#!/usr/bin/python3
"""
    function prime game
"""


def get_primes(n):
    """ 
        get all primes until the limit with Sieve Of Eratosthene
        algorithm
    """
    m = n + 1
    numbers = [True] * m
    for i in range(2, int(n ** 0.5 + 1)):
        if numbers[i]:
            for j in range(i * i, m, i):
                numbers[j] = False
    primes = []
    for i in range(2, m):
        if numbers[i]:
            primes.append(i)
    return len(primes)


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
        nb_of_prime = get_primes(limit)
        if nb_of_prime % 2 == 0:
            ben += 1
        else:
            maria += 1
    if maria == ben:
        return None
    elif maria > ben:
        return 'Maria'
    else:
        return 'Ben'
