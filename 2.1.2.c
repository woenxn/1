#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// @brief вычисляет модуль числа
// @param число для получения модуля
// @return возвращает модуль числа
double getModul(const double number);

// @brief вычисляет среднее геометрическое
// @param num1 первое число
// @param num2 второе число
// @return возвращает среднее геометрическое
double getAverage(const double num1, const double num2);

// @brief считывает значение, введенное с клавиатуры с проверкой ввода
// @return считанное значение
double getValue();

// @brief точка входа в программу
// @return возвращает 0, если программа выполнена корректно
int main()
{
	printf("Введите 2 числа: ");
	double numb1 = getValue();
	double numb2 = getValue();
	double mod1 = getModul(numb1);
	double mod2 = getModul(numb2);
	printf("Среднее геометрическое модулей = %.4lf\n", getAverage(mod1, mod2));

	return 0;
}

double getModul(const double num)
{
	return abs(num);
}

double getAverage(const double num1, const double num2)
{
	return pow((num1*num2),0.5);
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
