#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

/*
*@brief Рассчитывает площадь прямоугольника
*@param x длина первой стороны
*@param y длина второй стороны
*@return возвращает рассчитанное значение площади прямоугольника
*/
double prmgl(const double x, const double y);

/*
*@brief Рассчитывает площадь треугольника по формуле Герона
*@param a длина первой стороны
*@param b длина второй стороны
*@param c длина третьей стороны
*@return возвращает рассчитанное значение площади треугольника
*/
double trgl(const double a, const double b, const double c);

/*
*@brief Точка входа в программу
*@return возвращает 0, если программа выполнена корректно
*/
int main()
{
    double x, y;
    double a, b, c;
    printf("Введите стороны прямоугольника: ");
    scanf("%lf %lf", &x, &y);
    printf("Введите три стороны треугольника: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    printf("Площадь прямоугольника равна %.2lf\n", prmgl(x, y));
    printf("Площадь треугольника равна %.2lf\n", trgl(a, b, c));
    return 0;
}

double prmgl(const double x, const double y)
{
    return x * y;
}

double trgl(const double a, const double b, const double c)
{
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
