#pragma warning(disable : 4996)
#include <stdio.h>
#define K 5
#define N 5

int main(void)
{
	int x[K][N];
	int i;//строки
	int j;//столбцы
	int max;//максимальное значение
	int sum;//сумма в диаогнале
	int maxi = 0;//максимальное i  в диагонале 
	int maxj = 0;//максимальное j  в диагонале
	int k;//счетчик для цикла в цикле
	int jo = -1;//первая точка в диагонале
	int io = -1;//первая точка в диагонале
	int q;//величина на которую смещаемся по диагонале
	q = 0;
	max = 0;
	sum = 0;

	srand(time(NULL));
	for (i = 0; i < N; i++)//задаем массив
	{
		for (j = 0; j < K; j++)
		{
			x[i][j] = 0 + rand() % 10;
		}
	}

	for (i = 0; i < N; i++)//выводим массив
	{
		for (j = 0; j < K; j++)
		{
			printf("%-2d ", x[i][j]);
		}
		printf("\n");
	}

	for (k = N - 1, j = 0; k >= 0; k--, sum = 0, j = 0)//считаем диагонали слева на право ниже главной оси
	{
		for (i = k; i < N; i++)
		{
			sum = x[i][j] + sum;
			j++;
		}
		if (sum >= max)
		{
			max = sum;
			maxi = i - 1;
			maxj = j - 1;
			jo = 0;
			io = N - 1 - q;
		}
		q++;
	}


	for (k = 1, i = 0, q = 0; k < N; k++, sum = 0, i = 0)//считаем диагонали слева на право выше главной оси
	{
		for (j = k; j < N; j++)
		{
			sum = x[i][j] + sum;
			i++;
		}
		if (sum >= max)
		{
			max = sum;
			maxi = i - 1;
			maxj = j - 1;
			io = 0;
			jo = 1 + q;
		}
		q++;
	}

	for (k = N - 1, j = N - 1, q = 0; k >= 0; k--, sum = 0, j = N - 1)//считаем диагонали справа на лево ниже главной оси
	{
		for (i = k; i < N; i++)
		{
			sum = x[i][j] + sum;
			j--;
		}
		if (sum >= max)
		{
			max = sum;
			maxi = i - 1;
			maxj = j + 1;
			io = N - 1 - q;
			jo = N - 1;
		}
		q++;
	}

	for (k = N - 2, i = 0,q = 0; k >= 0; k--, sum = 0, i = 0)//считаем диагонали справа на лево выше главной оси
	{
		for (j = k; j >= 0; j--)
		{
			sum = x[i][j] + sum;
			i++;
		}
		if (sum >= max)
		{
			max = sum;
			maxi = i - 1;
			maxj = j + 1;
			jo = N - 2 - q;
			io = 0;
		}
		q++;
	}
	if ((jo == 0)&(maxj == j-1))
	{
		for (i = io, j = jo; i < N; i++)
		{
			x[i][j] = 0;
			j++;
		}
	}


	if ((io == 0) && (maxj == N - 1))
	{
		for (i = io, j = jo; j < N; i++)
		{
			x[i][j] = 0;
			j++;
		}
	}


	if (jo == N - 1)
	{
		for (i = io, j = jo; i < N; i++)
		{

			x[i][j] = 0;
			j--;
		}
	}

	if ((io == 0) && (maxj == 0))
	{
		for (i = io, j = jo; j >= 0; j--)
		{
			x[i][j] = 0;
			i++;
		}
	}
	
	printf("\n");
	printf("\n");
	printf("\n");
	for (i = 0; i < N; i++)//выводим массив
	{
		for (j = 0; j < K; j++)
		{
			printf("%-2d ", x[i][j]);
		}
		printf("\n");
	}

	return 0;
}
