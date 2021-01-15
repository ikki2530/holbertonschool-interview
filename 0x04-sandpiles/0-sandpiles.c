#include <stdio.h>

/**
 * print_grid - prints grid.
 *
 * @grid: grid to print.
 */

static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - checks if sand pile is stable
 *
 * @grid: grid to check.
 * Return: 1 if stable 0 if not.
 */
int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * sandpiles_simple_sum - sums sandpiles.
 *
 * @grid1: grid1.
 * @grid2: grid2.
 * The simple sand pile sum (without topping).
 */

void sandpiles_simple_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, c = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			c = grid1[i][j] + grid2[i][j];
			grid2[i][j] = c;
			grid1[i][j] = c;
		}
	}
}

/**
 * sandpiles_sum - inserts a value.
 * @grid1: grid one.
 * @grid2: grid two.
 * Return: The new node or null.
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	sandpiles_simple_sum(grid1, grid2);

	while (!(is_stable(grid1)))
	{
		printf("=\n");
		print_grid(grid1);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
				{
				if (grid1[i][j] > 3)
					grid1[i][j] -= 4;
				if ((i > 0) && (grid2[i - 1][j] > 3))
					grid1[i][j] += 1;
				if ((i < 2) && (grid2[i + 1][j] > 3))
					grid1[i][j] += 1;
				if ((j > 0) && (grid2[i][j - 1] > 3))
					grid1[i][j] += 1;
				if ((j < 2) && (grid2[i][j + 1] > 3))
					grid1[i][j] += 1;
				}
		}
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
				grid2[i][j] = grid1[i][j];
		}

	}
}
