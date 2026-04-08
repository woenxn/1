#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief считывает целое значение введенное с клавиатуры с проверкой ввода
 * @return Введенное значение
 */
int getValue();

/**
 * @brief считывает вещественное значение введенное с клавиатуры с проверкой ввода
 * @return возвращает считанное значение
 */
double getDouble();

/**
 * @brief рассчитывает сумму n членов последовательности
 * @param n - заданное число членов
 * @return рассчитанное значение
 */
double sumN(const int n);

/**
 * @brief рассчитывает сумму членов последовательности, с точностью e
 * @param e - заданная точность
 * @return рассчитанное значение
 */
double sumE(const double e);

/**
 * @brief рассчитывает коэффициент рекуррентного выражения
 * @param i текущий индекс (начинается с 0)
 * @param current текущее значение члена последовательности
 * @return рассчитанное значение следующего члена
 */
double rec(const int i, const double current);

/** 
 * @brief проверяет, что число положительное
 * @param value - проверяемое значение
 */
void checkPositive(const double value);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main()
{
    printf("Введите n: ");
    int n = getValue();
    checkPositive(n);
    printf("Сумма %d чисел последовательности равна %.10lf\n", n, sumN(n));
    
    printf("Введите e: ");
    double e = getDouble();
    checkPositive(e);
    printf("Сумма последовательности с точностью %lf равна %.10lf\n", e, sumE(e));

    return 0;
}

int getValue()
{
    int value = 0;
    if (!scanf("%d", &value))
    {
        printf("Error, введено неверное значение\n");
        exit(1);
    }
    return value;
}

double getDouble()
{
    double value = 0;
    if (!scanf("%lf", &value))
    {
        printf("Error, введено неверное значение\n");
        exit(1);
    }
    return value;
}

double sumN(const int n)
{
    double current = 1.0;
    double result = current;
    
    for (int k = 1; k < n; k++)
    {
        current = rec(k, current);
        result += current;
    }
    return result;
}

double rec(const int k, const double current)
{
    return current * (-1.0) / k;
}

void checkPositive(const double value)
{
    if (value <= 0)
    {
        printf("Error, число должно быть положительным\n");
        exit(1);
    }
}

double sumE(const double e)
{
    double current = 1.0;
    double result = current;
    int k = 1;
    
    while (fabs(current) >= e)
    {
        current = rec(k, current);
        result += current;
        k++;
    }
    return result;
}
