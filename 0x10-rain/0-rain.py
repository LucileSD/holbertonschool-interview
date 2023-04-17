#!/usr/bin/python3
"""0. Rain"""
def rain(walls):
    """calculate how many square units of water will be retained
       after it rains
       args:
        walls: list of non-negative integers.
       return: units of water will be retained otherwise 0
    """
    tmp = 0
    rain = 0
    other = 0
    x = 0
    if walls == None:
        return 0
    for number in range(0, len(walls) - 1):
        if walls[number] != 0:
            if walls[number] > tmp:
                tmp = walls[number]
            else:
                other = walls[number] - tmp
                x = number
                while (walls[x - 1] == 0):
                    rain += other
                    x -= 1
        if walls[number] == 0:
            rain += tmp
    return rain

