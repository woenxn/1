#define _USE_MATH_DEFINES // for C
#include <stdio.h>
#include <math.h>

/**
* @brief Рассчитывает функцию B по заданной формуле
* @param x - значение параметра x
* @param y - значение параметра y
* @param z - значение параметра z
* @return рассчитанное значение
*/
double getB(const double x, const double y, const double z);

/**
* @brief Рассчитывает функцию А по заданной формуле
* @param x - значение параметра x
* @param y - значение параметра y
* @param z - значение параметра z
* @return рассчитанное значение
*/
double getA(const double x, const double y, const double z);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа выполнена корректно
*/
int main()
{
	const double x = -4.8;
	const double y = 17.5;
	const double z = 3.2;
	printf("A=%lf", getA(x, y, z));
	printf("B=%lf", getB(x, y, z));
	return 0;
}

double getB(const double x, const double y, const double z)
{
	return z * pow(exp(1), -sqrt(z)) * cos(y * x / z);
}

double getA(const double x, const double y, const double z)
{
	return y * z * pow(x, 2) - z / pow(sin(x / z), 2);
}
