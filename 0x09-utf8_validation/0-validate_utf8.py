#!/usr/bin/python3
"""
Determines if a given data set represents a valid UTF-8 encoding.
"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding.
    Return: True if data is a valid UTF-8 encoding, else return False
    """
    m1 = 1 << 7
    m2 = 1 << 6
    nbytes = 0
    for i in data:
        bit = 1 << 7
        if nbytes == 0:
            while bit & i:
                nbytes += 1
                bit = bit >> 1
            if nbytes == 0:
                continue
            if nbytes == 1 or nbytes > 4:
                return False
        else:
            if not (i & m1 and not (i & m2)):
                return False
        nbytes -= 1
    return nbytes == 0
