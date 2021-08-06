#!/usr/bin/python3
"""Pascal triangle method"""


def pascal_triangle(n):
    """Function that returns a list of lists of
    integers representing the Pascal’s triangle of n"""
    matrix = []
    if n <= 0:
        return matrix
    for i in range(1, (n + 1)):
        submatrix = []
        for j in range(i):
            submatrix.append(1)
        matrix.append(submatrix)
    for i in range(len(matrix)):
        for j in range(i):
            if j != 0:
                matrix[i][j] = matrix[i - 1][j] + matrix[i - 1][j - 1]
    return matrix
