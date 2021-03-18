#!/usr/bin/python3
"""
The N queens puzzle is the challenge of
placing N non-attacking queens on an N×N chessboard.
Write a program that solves the N queens problem.
"""

import sys


def print_board(board):
    """ print_board
    Args:
        board - list of list with length sys.argv[1]
    """
    new_list = []
    for i, row in enumerate(board):
        value = []
        for j, column in enumerate(row):
            if column == 1:
                value.append(i)
                value.append(j)
        new_list.append(value)

    print(new_list)


def isSafe(board, row, column, number):
    """ isSafe
    Args:
        board - list of list with length sys.argv[1]
        row - row to check if is safe doing a movement in this position
        column - column to check if is safe doing a movement in this position
        number: size of the board
    Return: True of False
    """

    # Check this row in the left side
    for i in range(column):
        if board[row][i] == 1:
            return False

    # Check upper diagonal on left side
    for i, j in zip(range(row, -1, -1), range(column, -1, -1)):
        if board[i][j] == 1:
            return False

    for i, j in zip(range(row, number, 1), range(column, -1, -1)):
        if board[i][j] == 1:
            return False

    return True


def solveNQUtil(board, column, number):
    """ Auxiliar method to find the posibilities of answer
    Args:
        board - Board to resolve
        column - Number of column
        number - size of the board
    Returns:
        All the posibilites to solve the problem
    """

    if (column == number):
        print_board(board)
        return True
        # print("hola")
    #  if (column == number):
    #     print_board(board)
    #     return True

    res = False
    for i in range(number):

        if (isSafe(board, i, column, number)):

            # Place this queen in board[i][column]
            board[i][column] = 1

            # Make result true if any placement
            # is possible
            res = solveNQUtil(board, column + 1, number) or res

            board[i][column] = 0  # BACKTRACK

    return res


def nqueens(n):
    """ Find all the posibilities if exists
    Args:
        n - board size
    """
    board = [[0 for i in range(n)]for i in range(n)]

    if not solveNQUtil(board, 0, n):
        return False

    return True


def validate(args):
    """ Validate the input data to verify if the size to
        answer is posible
    Args:
        args - sys.argv
    """
    if (len(args) == 2):
        # Check args
        try:
            number = int(args[1])
        except Exception:
            print("N must be a number")
            exit(1)
        if number < 4:
            print("N must be at least 4")
            exit(1)
        return number
    else:
        print("Usage: nqueens N")
        exit(1)


if __name__ == "__main__":
    """ Main method to execute the application
    """

    number = validate(sys.argv)
    nqueens(number)
