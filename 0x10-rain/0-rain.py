#!/usr/bin/python3
"""0. Rain"""


def rain(walls):
    """calculate how many square units of water will be retained
       after it rains
       args:
        walls: list of non-negative integers.
       return: units of water will be retained otherwise 0
    """
    rain = 0

    for number in range(0, len(walls) - 1):
        left = walls[number]
        for l_num in range(number):
            left = max(left, walls[l_num])

        right = walls[number]
        for r_num in range(number + 1, len(walls)):
            right = max(right, walls[r_num])

        rain += min(left, right) - walls[number]

    return rain
