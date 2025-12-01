#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>
#include <math.h>

/**
 * @brief считывает значение, введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/**
 * @brief проверяет,чтобы переменная была положительная
 * @param step значение проверяемой переменной
 */
void checkStep(const double step);

/**
 * @brief рассчитывает значение функции y по формуле
 * @param x значение
 * @return значение функции
 */
double getY(const double x);

/**
 * @brief точка входа в программу
 * @return возвращает 0, если программа выполнена корректно, 1 - если некорректно.
 */
int main()
{
	printf("Введите исходное значение: ");
	double start = getValue();
	printf("Введите конечное значение: ");
	double end = getValue();
	printf("Введите значение шага: ");
	double step = getValue();
	checkStep(step);
	
	double x = start;
	while (x < end + DBL_EPSILON)
	{
		printf("x = %.2lf, y = %.4lf\n", x, getY(x));
		x = x + step;
	}
	return 0;
}

double getValue()
{
	double value = 0;
	if (!scanf("%lf", &value))
	{
		printf("Ошибка\n");
		abort();
	}
	return value;
}

void checkStep(const double step)
{
	if (step <= DBL_EPSILON)
	{
		printf("Error, шаг должен быть положительным\n");
		abort();
	}
}

double getY(const double x)
{
	return x - 1 / (3 + sin(3.6 * x));
}
