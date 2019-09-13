#pragma warning(disable : 4996)
#include <stdio.h>
#define YES 1
#define NO 0
#define MAXLINE 1000

void process_line(char buffer[]);

int main(void)
{
	char line[MAXLINE];
	printf("please, enter some words \n");
	gets(line);
	process_line(line);
	puts(line);
	return 0;
}

void process_line(char buffer[])

{
	char c;// Текущий символ
	int word = NO;//признак слова
	int symb = NO;//индикатор наличия лишних символов
	int cur = 0;//позиция текущего символа исходной строки
	int res = 0;//позиция текущего символа результирующей строки
	int start = 0;//позиция начала слова
	int vowel = 0;//счетчик гласных букв
	int conso = 0;// счетски согласных букв
	int j;

	do
	{
		c = buffer[cur]; // взять текущий символ из буфера
		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0' || c == '?' || c == '!' || c == ';' || c == ':' ||
			c == '-' || c == '_' || c == '(' || c == ')' || c == '\t' || c == '/' || c == '&' || c == '"') // разделитель найден
		{
			if (symb == NO && word == YES && conso >= vowel || symb == NO && word == YES)
			{
				for (j = start; j <= cur; j++)
				{
					buffer[res++] = buffer[j];//копируем слово
				}
			}
			else
			{
				buffer[res++] = buffer[cur];//возвращаем разделитель на место
			}
			word = NO;
			symb = NO;
			conso = 0;
			vowel = 0;
		}

		else
		{
			if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z')) // проверить не является ли этот символ лишним
			{
				symb = YES; // в слове есть лишний символ
			}
			if (word == NO) // найдена первая буква слова
			{
				start = cur; // запомнить позицию начала слова
			}
			if (c == 'e' || c == 'y' || c == 'u' || c == 'i' || c == 'o' || c == 'a' ||
				c == 'E' || c == 'Y' || c == 'U' || c == 'I' || c == 'O' || c == 'A') // если была найдена гл буква, то выполнить...
			{
				vowel++;
			}
			if (c == 'b' || c == 'c' || c == 'd' || c == 'f' || c == 'g' || c == 'h' || c == 'j' || c == 'k' || c == 'l' || c == 'm' || c == 'n' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't'
				|| c == 'v' || c == 'w' || c == 'x' || c == 'z' || c == 'B' || c == 'C' || c == 'D' || c == 'F' || c == 'G' || c == 'H' || c == 'J' || c == 'K' || c == 'L' || c == 'M' || c == 'N' ||
				c == 'P' || c == 'Q' || c == 'R' || c == 'S' || c == 'T' || c == 'V' || c == 'W' || c == 'X' || c == 'Z')
			{
				conso++;
			}
			word = YES;
		}

		cur++;
	} while (c != '\0'); // продолжать до конца строки
	buffer[res] = '\0';// устанавливаем конец файла

}
