#include <stdio.h>

int sumArea(int i, int j, int L, int C, int S, int matrix[L][C])
{
	int sum = 0;
	for (int line = i; line < i + 3; line++)
	{
		for (int column = j; column < j + 3; column++)
		{
			sum += matrix[line][column];
		}
	}

	return S - sum;
}

int main()
{
	int L, C, S, currentSum = 0, bestSum = 'NULL', bestLine, bestCol;
	scanf("%i %i %i", &L, &C, &S);
	int matrix[L][C];

	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < C; j++)
		{
			scanf("%i", &matrix[i][j]);
		}
	}

	for (int i = 0; i < L - 2; i++)
	{
		for (int j = 0; j < C - 2; j++)
		{
			currentSum = sumArea(i, j, L, C, S, matrix);
			if (bestSum == 'NULL')
			{
				bestSum = abs(currentSum);
				bestLine = i + 1;
				bestCol = j + 1;
			}
			else
			{
				currentSum = abs(currentSum);
				if (currentSum < bestSum)
				{
					bestSum = currentSum;
					bestLine = i + 1;
					bestCol = j + 1;
				}
			}
		}
	}
	printf("A melhor area para exploracao eh %i %i com valor %i", bestLine, bestCol, bestSum);
	return 0;
}