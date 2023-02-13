#!/usr/bin/python3
"""determines if a given data set represents a valid UTF-8 encoding"""


def validUTF8(data):
    """a method that determines if a given data set represents
       a valid UTF-8 encoding
       args: data: data to check
       return: True if data is valid UTF-8 otherwise False
    """
    try:
        bytes(data)
    except ValueError:
        return False
    return True
