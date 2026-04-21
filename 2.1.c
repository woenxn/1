#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
* @brief рассчитывает модуль числа
* @param numb число
* @return возвращает модуль числа
*/
double getModul(const double numb);
/**
* @brief рассчитывает куб числа
* @param numb число
* @return возвращает куб числа
*/
double getCube(const double numb);
/**
* @brief рассчитывает среднее арифмитическое двух чисел
* @param numb1 первое число
* @param numb2 второе число
* @return возвращает среднее арифмтическое чисел
*/
double getAverage(const double numb1, const double num2);
/**
* @brief считывает значение, введеное с клавиатуры
* @return считанное значение
*/
double getValue();
/**
* @brief cube - куб числа
* @bried modul - модуль числа
*/
enum {cube, modul};
/**
* @brief точка входа в программу
* @return возвращает 0, если программа выполнена верно
*/
int main(void)
{
	printf("Введите два числа: ");
	double numb1 = getValue();
	double numb2 = getValue();
	printf("Выберите подсчёт: %d-среднее арифмтическое кубов, %d-среднее арифмитическое модулей\n", cube, modul);
	int choice = (int)getValue();
	switch (choice)
	{
	case cube:
		printf("Среднее арифмитическое кубов равно %.2lf", getAverage(getCube(numb1), getCube(numb2)));
		break;
	case modul:
		printf("Среднее арифмитическое модулей равно %.2lf", getAverage(getModul(numb1), getModul(numb2)));
		break;
	default:
		printf("Неправильный выбор");
		abort();
	}
	return 0;
}

double getCube(const double number)
{
	return pow(number, 3);
}

double getModul(const double number)
{
	return fabs(number);
}

double getAverage(const double num1, const double num2)
{
	return (num1 + num2) / 2;
}

double getValue()
{
	double value = 0;
	if (!scanf("%lf", &value))
	{
		printf("error\n");
		abort();
	}
	return value;
}






