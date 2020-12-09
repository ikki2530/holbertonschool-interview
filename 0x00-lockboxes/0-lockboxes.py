#!/usr/bin/env python3
"""Lockboxes"""


def canUnlockAll(boxes):
    """
    Description: determines if all the boxes can be opened.
    boxes: is a list of lists
    returns: True in case that all boxes can be opened, False otherwise
    """
    lg = len(boxes)
    visitados = []
    i = 0
    while i < lg:
        visitados.append(0)
        i += 1
    j = 0
    if lg != 0:
        visitados[0] = 1
        lg0 = len(boxes[0])
    j = 0
    while j < lg0:
        op, v = unlock(boxes, visitados, boxes[0][j], 0)
        if op and 0 not in v:
            return True
        j += 1
    return False


def unlock(boxes, visitados, index, prev_idx):
    """
    Description: helper function for unlock boxes
    boxes: is a list of lists
    visitados: 0 not visited, other numbers for other cases
    index: index of current box
    prev_idx: index of the previous box
    returns: A tuple with (open, visitados)
    """
    if visitados[prev_idx] > len(boxes[prev_idx]) and visitados[index] > 1:
        return False, visitados

    visitados[index] += 1
    lg_index = len(boxes[index])
    i = 0
    while i < lg_index:
        # print("i value", i)
        op, v = unlock(boxes, visitados, boxes[index][i], index)
        if 0 not in v:
            return True, visitados
        i += 1
    return False, visitados
