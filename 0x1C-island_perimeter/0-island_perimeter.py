#!/usr/bin/python3
"""
    calculate the perimeter of an island in a grid
    args:
        grid
    return:
        the perimeter
"""


def island_perimeter(grid):
    row = len(grid)
    if row == 0 or len(grid[0]) == 0:
        return 0
    col = len(grid[0])
    islands, overlaps = 0, 0
    for line in range(row):
        for num in range(col):
            if (grid[line][num] == 1):
                islands += 1
                if (line < row - 1 and grid[line + 1][num] == 1):
                    overlaps += 1
                if (num < col - 1 and grid[line][num + 1] == 1):
                    overlaps += 1
    return islands * 4 - overlaps * 2
