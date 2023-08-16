#!/usr/bin/python3
"""
    pascal trinagle function
"""


def pascal_triangle(n):
    """
        the Pascal’s triangle of n
        args:
            n: the number
        return:
            a list of lists of integers
    """
    triangle = []

    for line in range(n):
        inner_list = []
        for idx in range(line + 1):
            if idx == 0 or idx == line:
                inner_list.append(1)
            else:
                inner_list.append(triangle[line - 1][idx - 1] +
                                  triangle[line - 1][idx])
        triangle.append(inner_list)

    return triangle
