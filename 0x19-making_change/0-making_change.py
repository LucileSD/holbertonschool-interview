#!/usr/bin/python3
"""
    Change comes from within
"""


def makeChange(coins, total):
    """
        makeChange: know the minimum of coins needed to meet the total
        coins: an array with the coins values
        total: the number to meet
        return: the minimum of coins or -1
    """
    if total == 0:
        return 0

    min_coins = [float('inf')] * (total + 1)

    min_coins[0] = 0

    for coin in coins:
        for i in range(coin, total + 1):
            min_coins[i] = min(min_coins[i], min_coins[i - coin] + 1)

    if min_coins[total] == float('inf'):
        return -1

    return min_coins[total]
