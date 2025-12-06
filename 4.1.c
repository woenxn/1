#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define scanf_s scanf

/**
 * @brief Считывает введённое с клавиатуры целое значение и проверяет на правильность ввода
 * @return введённое значение
 */
int Value(void);

/**
 * @brief Выводит сообщение о необходимости ввода размера массива, проверяет ввод на правильность, задаёт размер массива
 * @param message текстовое сообщение о необходимости ввода массива
 * @return размер массива (количество элементов)
 */
size_t getSize(char* message);

/**
 * @brief Считывает значения элементов массива
 * @param arr массив
 * @param size размер массива
 */
void fillArray(int* arr, const size_t size);

/**
 * @brief Выводит массив (элементы)
 * @param arr массив
 * @param size размер массива
 */
void printArray(int* arr, const size_t size);

/**
 * @brief Вычисляет сумму отрицательных элементов массива
 * @param arr массив
 * @param size размер массива
 */
void sumNegative(int* arr, const size_t size);

/**
 * @brief Заполняет массив случайными числами в пределах введённого пользователем диапазона
 * @param arr массив
 * @param size размер массива
 */
void fillRandom(int* arr, const size_t size);

/**
 * @brief Создаёт копию массива
 * @param arr массив
 * @param size размер массива
 * @return полученный массив
 */
int* copyArray(const int* arr, const size_t size);

/**
 * @brief Находит номер последней пары соседних элементов с разными знаками
 * @param copyArr копия массива
 * @param size размер массива
 * @return Возвращает 1, если функция выполнена корректно, 0 - если в массиве отсутствуют пары с разными знаками
 */
int findLastDifferentSignPair(int* copyArr, const size_t size);

/**
 * @brief Считает количество положительных элементов, не превосходящих заданное число А
 * @param arr массив
 * @param size размер массива
 */
void countPositiveLessThanA(int* arr, const size_t size);

/**
 * @brief RANDOM - заполнение массива случайными числами в пределах введённого пользователем диапазона
 * @brief MANUAL - заполнение массива вручную
 */
enum {RANDOM = 1, MANUAL};

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1.
 */
int main(void)
{
    size_t size = getSize("Введите размер массива:\n");
    int* arr = malloc(size* sizeof(int));
    if (arr == NULL)
    {
        fprintf(stderr,"Ошибка");
        exit(1);
    }
    printf("Выберите способ заполнения массива:\n%d - случайными числами\n%d - вручную\n", RANDOM, MANUAL);
    int choice = Value();
    switch(choice)
        {
            case RANDOM:
                fillRandom(arr, size);
                break;
            case MANUAL:
                fillArray(arr, size);
                break;
            default:
                fprintf(stderr,"Ошибка.");
                free(arr);
                exit(1);
        }
    printArray(arr, size);
    printf("\n");
    sumNegative(arr, size);
    printf("\n");
    countPositiveLessThanA(arr, size);
    printf("\n");
    int* copyArr = copyArray(arr, size);
    findLastDifferentSignPair(copyArr, size);
    free(copyArr);
    free(arr);
    return 0;
}

int Value(void)
{
    int value = 0;
    int result = scanf("%d", &value);
    if (result != 1){
        fprintf(stderr, "Ошибка ввода");
        exit(1);
    }
    return value;
}

size_t getSize(char* message)
{
    printf("%s", message);
    int value = Value();
    if (value <= 0)
    {
        fprintf(stderr,"Ошибка ввода");
        exit(1);
    }
    return (size_t)value;
}

void fillArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Введите %zu элемент массива:", i);
        arr[i] = Value();
    }
}

void printArray(int* arr, const size_t size)
{
    printf("Ваш массив:\n");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sumNegative(int* arr, const size_t size)
{
    int result = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] < 0)
            {
                result += arr[i];
            }
    }
    printf("Сумма отрицательных чисел: %d.\n", result);
}

void fillRandom(int* arr, const size_t size)
{
    printf("Начало диапазона:\n");
    int start = Value();
    printf("Конец диапазона:\n");
    int end = Value();
    if (start >= end) {
        fprintf(stderr, "Ошибка: конец должен быть больше начала\n");
        exit(1);
    }
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % (end - start + 1) + start;
    }
}

int* copyArray(const int* arr, const size_t size)
{
    int* copyArr = malloc(sizeof(int)*size);
    for (size_t i = 0; i<size; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}

void countPositiveLessThanA(int* arr, const size_t size) {
    printf("Введите число А: ");
    int A = Value();
    int count = 0;

    for (size_t i = 0; i < size; i++) {
        if (arr[i] > 0 && arr[i] <= A) {
            count++;
        }
    }
    printf("Количество положительных элементов не превышающих %d: %d.\n", A, count);
}

int findLastDifferentSignPair(int* copyArr, const size_t size) {
    if (size < 2) {
        printf("Размер массива слишком мал для поиска пар.\n");
        return 0;
    }
    
    int lastIndex = -1;
    
    for (size_t i = 0; i < size - 1; i++) {
        if ((copyArr[i] > 0 && copyArr[i+1] < 0) || (copyArr[i] < 0 && copyArr[i+1] > 0)) {
            lastIndex = i;
        }
    }
    
    if (lastIndex != -1) {
        printf("Индекс последней пары с разными знаками: %d (элементы: %d и %d).\n", 
               lastIndex, copyArr[lastIndex], copyArr[lastIndex + 1]);
        return 1;
    } else {
        printf("В массиве нет пар с разными знаками.\n");
        return 0;
    }
}
