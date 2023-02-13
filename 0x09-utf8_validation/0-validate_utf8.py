#!/usr/bin/python3
"""determines if a given data set represents a valid UTF-8 encoding"""


from math import ceil, log

def validUTF8(data):
    """a method that determines if a given data set represents
       a valid UTF-8 encoding
       args: data: data to check
       return: True if data is valid UTF-8 otherwise False
    """
    list_utf_8 = []
    for nb in data:
        if nb == 0:
            list_utf_8.append(0)
        else:
            list_utf_8.append(ceil(log(nb) / log(2)))
    for bytes in list_utf_8:
        if bytes > 7:
            return False
    return True
