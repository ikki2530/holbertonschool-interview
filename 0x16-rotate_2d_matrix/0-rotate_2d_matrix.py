#!/usr/bin/python3
"""
Function Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """
    Given an n x n 2D matrix, rotate it 90 degrees.
    Arguments:
    - matrix an n x n 2D matrix
    Returns:
     Nothing, the matrix must be edited in-place.
    """
    L = len(matrix[0])

    for i in range(L // 2):
        L1 = L - 1
        for j in range(i, L1 - i):
            temp = matrix[i][j]
            matrix[i][j] = matrix[L1 - j][i]
            matrix[L1 - j][i] = matrix[L1 - i][L1 - j]
            matrix[L1 - i][L1 - j] = matrix[j][L1 - i]
            matrix[j][L1 - i] = temp
