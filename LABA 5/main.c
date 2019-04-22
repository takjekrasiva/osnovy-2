#pragma warning(disable:4996)
#include <stdio.h>
#define N 10

int main(void)
{
	int x[N];//массив из N эллементов
	int even;//счетчки четных
	int ord;//счетчик нечетных
	int i;
	even = 0;
	ord = 0;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &x[i]);
		if (x[i] % 2 == 0)
		{
			even++;
		}
		else
		{
			ord++;
		}
	}
	if (even == ord)
	{}
	else
	{
		if (even > ord)
		{
			for (i = 0; i < N; i++)
			{
				if (x[i] % 2 != 0)
				{
					x[i] = 0;
				}
			}
		}
		else
		{
			for (i = 0; i < N; i++)
			{
				if (x[i] % 2 == 0)
				{
					x[i] = 0;
				}
			}
		}
	}
	
	for (i = 0; i < N; i++)
	printf("%d ", x[i]);
	return 0;

}
