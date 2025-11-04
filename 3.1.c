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
 * @brief проверяет, принадлежит ли значение аргумента функции её области определения
 * @param x - аргумент функции
 * @return true, если аргумент принадлежит ООФ, else false
 */

bool defineOOF(const double x);

/**
 * @brief рассчитывает значение функции y по формуле
 * @param x значение
 * @return
 */

double getY(const double x);

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
		if (defineOOF(x))
		{
			printf("x = %.2lf, y = %.4lf\n", x, getY(x));
		}
		else
		{
			printf("x = %.2lf, не принадлежит ООФ\n", x);
		}
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

bool defineOOF(const double x)
{
	return x <= 0.85;
}

double getY(const double x)
{
	return x - 1 / (3 + sin(3.6 * x));
}
