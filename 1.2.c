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
    double x = 0, y = 0;
    double a = 0, b = 0, c = 0;
    printf("Введите стороны прямоугольника (длина и ширина): ");
    scanf("%lf %lf", &x, &y);
    if (x <= 0 || y <= 0)
    {
        printf("Ошибка: стороны прямоугольника должны быть положительными числами\n");
        return 1;
    }
    printf("Введите три стороны треугольника: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a <= 0 || b <= 0 || c <= 0)
    {
        printf("Ошибка: стороны треугольника должны быть положительными числами\n");
        return 1;
    }
    if(a + b <= c || a + c <= b || b + c <= a)
    {
        printf("Ошибка: такие стороны не могут образовать треугольник\n");
        return 1;
    }
    printf("\nРезультаты вычислений:\n");
    printf("Площадь прямоугольника (%.2lf x %.2lf) = %.2lf\n", x, y, prmgl(x, y));
    printf("Площадь треугольника (%.2lf, %.2lf, %.2lf) = %.2lf\n", a, b, c, trgl(a, b, c));
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
