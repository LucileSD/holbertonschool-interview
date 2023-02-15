#!/usr/bin/python3
"""determines if a given data set represents a valid UTF-8 encoding"""


def validUTF8(data):
    """a method that determines if a given data set represents
       a valid UTF-8 encoding
       args: data: data to check
       return: True if data is valid UTF-8 otherwise False
    """
    n_bytes = 0
    mask1 = 1 << 7
    mask2 = 1 << 6

    for num in data:
        mask = 1 << 7
        if n_bytes == 0:
            while mask & num:
                n_bytes += 1
                mask = mask >> 1

            if n_bytes == 0:
                continue

            if n_bytes == 1 or n_bytes > 4:
                return False
        else:
            if not (num & mask1 and not (num & mask2)):
                return False
        n_bytes -= 1
    return n_bytes == 0
