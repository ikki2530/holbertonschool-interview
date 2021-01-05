#!/usr/bin/python3
"""
Minimun operations
"""


def minOperations(n):
    """
    - Calculates the fewest number of operations needed to result in exactly
    n H characters in the file.
    - n: number of times the character H is added.
    Returns an integer, If n is impossible to achieve, return 0
    """
    if type(n) != int or n <= 1:
        return 0
    result = "H" * n
    copy = True
    copied = ""
    temp = "H"
    c = 0
    while True:
        if copy:
            # Copy all
            copied = temp
            copy = False
            c += 1
        else:
            # paste
            temp += copied
            c += 1
            if n % len(temp) == 0:
                copy = True
        if temp == result:
            break
    return c
