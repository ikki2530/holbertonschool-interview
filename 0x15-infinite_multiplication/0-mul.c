
#include "holberton.h"

/**
 * free_grid - Function that help to free memory
 * @height: interator
 * @grid: input double pointer
 * Return: Nothing (void)
 */

void free_grid(int **grid, int height)
{
	int j;

	if (grid != NULL && height > 0)
	{
		for (j = 0; j < height; j++)
		{
			free(grid[j]);
		}
		free(grid);
	}
}

/**
 * free_all - Function that free all memory
 * @sum: double pointer matrix
 * @size_v: size vertical matrix
 * @n1: number 1 to multiply
 * @n2: number 2 to multiply
 * @answer: pointer to answer
 * Return: Nothing (void)
 */

void free_all(int *sum[], int size_v, int *n1, int *n2, int *answer)
{
	free_grid(sum, size_v);
	free(n1);
	free(n2);
	free(answer);
}

/**
 * print_answer - Function that prints the answer.
 * @answer: pointer to the array answer
 * @size_h: size of the answer
 * Return: Nothing (void)
 */

void print_answer(int *answer, int size_h)
{
	int i, j = 0;

	for (i = 0; i < size_h; i++)
	{
		if (answer[i] != 0)
			j = 1;
		if (j != 0)
			_putchar(answer[i] + 48);
	}
	_putchar(10);

}

/**
 * sum_up - Function to sum up horizontal matrix.
 * @sum: pointer to the matrix
 * @answer: pointer to the array answer
 * @size_h: size of the answer
 * @size_v: size of the vertical matrix
 * Return: Nothing (void)
 */

void sum_up(int *sum[], int *answer, int size_h, int size_v)
{
	int i, j, carrier = 0;

	for (i = size_h - 1; i >= 0; i--)
	{
		answer[i] = 0;
		for (j = 0; j < size_v; j++)
		{
			answer[i] += sum[j][i];
		}
		answer[i] += carrier;
		carrier = answer[i] / 10;
		answer[i] %= 10;
		if (i == 0)
			answer[0] = carrier;
	}
}

/**
 * fill_zeros - Function to fill a matrix with 0
 * @sum: pointer to the matrix
 * @size_h: size of the answer
 * @size_v: size of the vertical matrix
 * Return: Nothing (void)
 */

void fill_zeros(int *sum[], int size_v, int size_h)
{
	int i, j;

	for (i = 0; i < size_v; i++)
	{
		for (j = 0; j < size_h; j++)
			sum[i][j] = 0;
	}
}


/**
 * to_number - Function to change a number from string to integer
 * @argv: number as string
 * @size: size of the array number
 * @n: array to put the number
 * Return: Nothing (void)
 */

void to_number(char argv[], int size, int n[])
{
	int i;

	for (i = 0; i < size; i++)
	{
		n[i] = argv[i] - 48;
	}
}

/**
 * mul_line - Function that multiplies by one number a comlete line.
 * @n1: single number
 * @n2: complete number
 * @size: size of the complete number
 * @size_v: size of the horizantal matrix
 * @sum: double pointer matrix
 * @level: depth of the matrix
 * Return: Nothing (void)
 */

void mul_line(int n1, int *n2, int size, int size_v, int **sum, int level)
{
	int i, unid, carrier = 0;

	for (i = size; i > 0; i--)
	{
		unid = n1 * n2[i - 1] + carrier;
		if (unid > 9)
		{
			carrier = unid / 10;
			unid = unid % 10;
		}
		else
			carrier = 0;
		sum[level][size_v - level + i] = unid;
		if (i == 1)
			sum[level][size_v - level + i - 1] = carrier;
	}
}

/**
 * error - Function to print error and exit 98.
 * Return: Nothing (void)
 */

void error(void)
{
	int i;
	char err[] = "Error\n";

	for (i = 0; i <= 5; i++)
	{
		_putchar(err[i]);
	}
	exit(98);
}

/**
 * check_number - Function that checks if it is a valid number.
 * @argv: pointer to number as string
 * @lens: array with the length of the numbers 0 first number 1  second number
 * Return: Always 0
 */

int check_number(char *argv[], int lens[])
{
	int i, j, zeros = 0;

	for (j = 2; j >= 1; j--)
	{
		i = 0;
		while (argv[j][i] != 0)
		{
			if (argv[j][i] < 48 || argv[j][i] > 57)
				error();
			if (argv[j][i] != 48)
				zeros = 1;
			i++;
		}
		if (zeros == 0)
			return (1);
		zeros = 0;

		if (j == 2)
			lens[1] = i;
		else
			lens[0] = i;
	}
	return (0);
}

/**
 * main - Main function to prints the number of arguments passed into it.
 * @argc: - # of parameters
 * @argv: - array of parameters
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	int i, lens[2], **sum, *n1, *n2, zeros;
	int size_h, size_v, level, *answer;

	if (argc != 3)
		error();
	zeros = check_number(argv, lens);
	size_v = lens[0];
	size_h = lens[0] + lens[1] + 1;
	if (zeros)
	{
		_putchar('0'), _putchar(10);
		return (0);
	}
	sum = malloc((lens[0]) * sizeof(int *));
	if (sum == NULL)
		exit(98);
	for (i = 0; i < size_v; i++)
		sum[i] = malloc(size_h * sizeof(int));
	answer = malloc(size_h * sizeof(int));
	if (answer == NULL)
		exit(98);
	n1 = malloc((lens[0]) * sizeof(int));
	if (n1 == NULL)
		exit(98);
	n2 = malloc((lens[1]) * sizeof(int));
	if (n2 == NULL)
		exit(98);
	to_number(argv[1], lens[0], n1), to_number(argv[2], lens[1], n2);
	fill_zeros(sum, size_v, size_h);
	level = lens[0] - 1;
	while (level >= 0)
	{
		mul_line(n1[level], n2, lens[1], size_v, sum, lens[0] - level - 1);
		level--;
	}
	sum_up(sum, answer, size_h, size_v);
	print_answer(answer, size_h);
	free_all(sum, size_v, n1, n2, answer);
	return (0);
}
