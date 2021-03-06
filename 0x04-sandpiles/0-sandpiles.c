#include <stdio.h>

/**
 * print_grid - show complete grid
 * @grid: grid to be printed.
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
 * stable - checks if sand pile is stable.
 * @grid: to be checked.
 * Return: 1 if stable 0 if not.
 */
int stable(int grid[3][3])
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
 * sandpiles_short_sum - sums sandpiles.
 *
 * @grid1: grid1.
 * @grid2: grid2.
 * The simple sand pile sum (without topping).
 */
void sandpiles_short_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, w = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			w = grid1[i][j] + grid2[i][j];
			grid2[i][j] = w;
			grid1[i][j] = w;
		}
	}
}

/**
 * sandpiles_sum - inserts a value.
 * @grid1: grid one.
 * @grid2: grid two.
 * Return: The new node, null otherwise.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	sandpiles_short_sum(grid1, grid2);

	while (!(stable(grid1)))
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
