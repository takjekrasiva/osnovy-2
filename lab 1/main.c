#include <stdio.h> 
int main(void)
{
	float v1; // скорость авто
	float v2; // скорость мото
	float t; // время 
	float s1; // участок, который проехал авто за время
	float s2; // участок, который проехал мотоза время
	float s; // расстояние межда А и В

	printf("v1 ="); scanf("%f", &v1);
	printf("v2 ="); scanf("%f", &v2);
	printf("t ="); scanf("%f", &t);

	s1 = v1 * t;
	s2 = v2 * t;
	s = s1 + s2;

	printf("s=%f \n", s);
	return 0;
}
