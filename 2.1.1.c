#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// @brief вычисляет куб числа
// @param число для возведения в куб
// @return возвращает куб числа
double getCube(const double number);

// @brief вычисляет среднее арифмитическое
// @param num1 первое число
// @param num2 второе число
// @return возвращает среднее арифмитическое
double getAverage(const double num1, const double num2);

// @brief считывает значение, введенное с клавиатуры с проверкой ввода
// @считанное значение
double getValue();

// @brief точка входа в программу
// @return возвращает 0, если программа выполнена корректно
int main()
{
	printf("Введите 2 числа: ");
	double numb1 = getValue();
	double numb2 = getValue();
	double cube1 = getCube(numb1);
	double cube2 = getCube(numb2);
	printf("Среднее арифмитическое кубов = %.2lf\n", getAverage(cube1, cube2));

	return 0;
}

double getCube(const double num)
{
	return pow(num, 3);
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
		printf("Error\n");
		abort();
	}
	return value;
}
