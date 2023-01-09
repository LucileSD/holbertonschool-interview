#include "sandpiles.h"

/**
* print_grid - Print 3x3 grid
* @grid: 3x3 grid
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
* stability - check if grid is stable
* @grid: the grid to test
* Return: 1 if it is stable, otherwise 0
*/
int stability(int grid[3][3])
{
	int row, column;

	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
		{
			if (grid[row][column] > 3)
				return (0);
		}
	}
	return (1);
}

/**
* topple_sandpile - topple the sandpile if the pile is greater then 3
* @grid: the sandpile
* @grid_toppled: a sandpile empty at the beginning and keep the result
* of the toggle
*/
void topple_sandpile(int grid[3][3], int grid_toppled[3][3])
{
	int row, column;

	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
		{
			if (grid[row][column] > 3)
			{
				grid_toppled[row][column] += grid[row][column] - 4;
				if (column - 1 >= 0)
					grid_toppled[row][column - 1] += 1;
				if (column + 1 < 3)
					grid_toppled[row][column + 1] += 1;
				if (row - 1 >= 0)
					grid_toppled[row - 1][column] += 1;
				if (row + 1 < 3)
					grid_toppled[row + 1][column] += 1;
			}
			else
				grid_toppled[row][column] += grid[row][column];
		}
	}
}

/**
* sandpiles_sum - computes the sum of two sandpiles
* @grid1: first grid
* @grid2: second grid
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int ro, col, r, c, i, j;

	for (ro = 0; ro < 3; ro++)
	{
		for (col = 0; col < 3; col++)
		{
			grid1[ro][col] = grid1[ro][col] + grid2[ro][col];
		}
	}

	while (stability(grid1) != 1)
	{
		for (r = 0; r < 3; r++)
		{
			for (c = 0; c < 3; c++)
			{
				grid2[r][c] = 0;
			}
		}

		printf("=\n");
		print_grid(grid1);
		topple_sandpile(grid1, grid2);

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				grid1[i][j] = grid2[i][j];
			}
		}
	}
}
