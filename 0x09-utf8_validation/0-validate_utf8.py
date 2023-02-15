#!/usr/bin/python3
"""determines if a given data set represents a valid UTF-8 encoding"""


def validUTF8(data):
    """a method that determines if a given data set represents
       a valid UTF-8 encoding
       args: data: data to check
       return: True if data is valid UTF-8 otherwise False
    """
    i = 0
    while i < len(data):
        if data[i] < 128:
            n_bytes = 1
        elif 192 <= data[i] < 224:
            n_bytes = 2
        elif 224 <= data[i] < 240:
            n_bytes = 3
        elif 240 <= data[i] < 248:
            n_bytes = 4
        else:
            return False

        for j in range(i + 1, i + n_bytes):
            if j >= len(data) or data[j] < 128 or data[j] >= 192:
                return False

        i += n_bytes

    return True
