#!/usr/bin/python3
"""Make Change method"""


def makeChange(coins, total):
    """Given a pile of coins of different values, determine
    the fewest number of coins needed to meet a given amount"""
    n_coins = 0
    if total <= 0:
        return n_coins
    coins.sort(reverse=True)
    while (total > 0 and coins):
        n = int(total / coins[0])
        total = total - (coins[0] * n)
        n_coins = n_coins + n
        coins.remove(coins[0])
    if total != 0:
        return -1
    return n_coins
