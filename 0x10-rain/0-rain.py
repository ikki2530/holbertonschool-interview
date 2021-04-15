#!/usr/bin/python3
"""calculate how much water will be retained after it rains"""


def rain(walls):
    """calculate how much water will be retained after it rains"""
    n = len(walls)
    if n == 0:
        return 0
    lts = 0
    lft = [0] * n
    lft[0] = walls[0]
    rgt = [0] * n
    rgt[-1] = walls[-1]
    for i in range(1, n):
        lft[i] = max(lft[i - 1], walls[i])
    for i in range(n - 2, -1, -1):
        rgt[i] = max(rgt[i + 1], walls[i])
    for i in range(n):
        lts += min(lft[i], rgt[i]) - walls[i]
    return lts
