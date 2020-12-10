#!/usr/bin/env python3
"""Lockboxes"""


def canUnlockAll(boxes):
    """
    Description: determines if all the boxes can be opened.
    boxes: is a list of lists
    returns: True in case that all boxes can be opened, False otherwise
    # """
    unlock = []
    keys = []
    lg = len(boxes)
    for i in range(lg):
        unlock.append(0)
    unlock[0] = 1
    for j in range(len(boxes[0])):
        keys.append(boxes[0][j])

    for k in keys:
        # print("key:", k, "| keys:", keys, "| unlocked", unlock)
        if k < lg and unlock[k] == 0:
            unlock[k] = 1
        if k >= lg:
            continue
        for nk in boxes[k]:
            if nk not in keys:
                keys.append(nk)

    if 0 in unlock:
        return False
    else:
        return True
