#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>

/*
*@brief рассчитывает значение функции по заданным условиям
*@param x входное значение аргумента
*@return возвращает рассчитанное значение выбранной функции
*/
double function(const double x);

/*
*@brief считывает значение, введенное с клавиатуру с проверкой ввода
*@return считанное значение
*/
double getValue();

/*
*@brief точка входа в программу
*@param x выбранное пользователем значение аргумента
*@return возвращает 0, если программа выполнена корректно
*/
int main()
{
    printf("Программа для нахождения функции y:\n");
    printf("y=a/x+x^2 при x<4\n");
    printf("y=a*x+x^3 при x>=4\n");
    printf("const a=2.1\n");
    printf("Введите значение:\n");
    double x = getValue();
    double res = function(x);
    printf("Результат: y(%.2f)=%.2f\n", x, res);
    return 0;
}

double function(const double x)
{
    const double a = 2.1;
    if (x < 4 + DBL_EPSILON)
    {
        return a/x+pow(x,2);
    }
    else if (x >= 4 - DBL_EPSILON)
    {
        return a*x+pow(x,3);
    }
}

double getValue()
{
    double value = 0;
    if (!scanf("%lf", &value))
    {
        printf("Error, введено некорректное значение\n");
        abort();
    }
    return value;
}
