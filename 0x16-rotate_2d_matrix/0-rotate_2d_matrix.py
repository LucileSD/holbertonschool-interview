#!/usr/bin/python3
"""module to rotate"""


def rotate_2d_matrix(matrix):
    """rotate a 2D matrix at 90 degrees clockwise"""
    for row in range(len(matrix)):
        for element in range(row, len(matrix)):
            tmp = matrix[row][element]
            matrix[row][element] = matrix[element][row]
            matrix[element][row] = tmp

    for row in matrix:
        row.reverse()
