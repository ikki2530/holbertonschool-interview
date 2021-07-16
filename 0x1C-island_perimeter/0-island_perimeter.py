#!/usr/bin/python3
"""Function returns the perimeter of the island described in grid"""


def island_perimeter(grid):
    """Function returns the perimeter of the island described in grid
    grid is a list of list of integers:
        - 0 represents water
        - 1 represents land
        - Each cell is square, with a side length of 1
        - Cells are connected horizontally/vertically (not diagonally).
        - grid is rectangular, with its width and height not exceeding 100
    """
    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                if (j+1) < len(grid[0]) and grid[i][j+1] == 0:
                    perimeter += 1
                if j == (len(grid[0]) - 1):
                    perimeter += 1
                if grid[i][j-1] == 0 and j > 0:
                    perimeter += 1
                if j == 0:
                    perimeter += 1
                if grid[i-1][j] == 0 and i > 0:
                    perimeter += 1
                if i == 0:
                    perimeter += 1
                if (i+1) < len(grid) and grid[i+1][j] == 0:
                    perimeter += 1
                if i == len(grid) - 1:
                    perimeter += 1
    return (perimeter)
