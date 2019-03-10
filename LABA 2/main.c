#include <stdio.h> 

int main(void)
{
	float s;// сумма эллементов ряда
	int n;//число эллементов ряда
	float a;//элемент ряда
	float b;//знаменатель числа
	float c;//числитель числа
	int i;//номер элемента ряда
	int sign;// изменение знака

	printf("n=");//вводим количество элеиентов послежовательности 
	scanf("%d", &n);

	s = 0;
	c = 1;
	b = 1;
	sign = 1;
	i = 0;

	while( i < n )
	{
		a = c / b;
		s = s + a * sign;
		sign = -sign;
		c = c + 1;
		b = b * 2;
		i = i + 1;
	}
	printf("s = %f\n", s);//выводим результат
	return 0;
}
