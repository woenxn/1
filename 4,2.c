#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define scanf_s scanf  

/**
 * @brief Проверка выделения памяти
 * @param ptr Указатель на выделенную память
 */
void checkMemoryAllocation(void* ptr);

/**
 * @brief Считывает значение, введенное с клавиатуры с проверкой ввода
 * @return Считанное значение
 */
int getValue(void);

/**
 * @brief Получение размера массива
 * @param message сообщение пользователю
 * @return Размер массива
 */
size_t getSize(char* message);

/**
 * @brief Заполнение массива с клавиатуры
 * @param arr Указатель на массив
 * @param size Размер массива
 */
void fillArray(int* arr, const size_t size);

/**
 * @brief Вывод массива на экран
 * @param arr Указатель на массив
 * @param size Размер массива
 */
void printArray(const int* arr, const size_t size);

/**
 * @brief Проверяет корректность диапазона случайных чисел
 * @param start Начало диапазона
 * @param end Конец диапазона
 */
void checkRange(const int start, const int end);

/**
 * @brief Заполнение массива случайными числами
 * @param arr Указатель на массив
 * @param size Размер массива
 */
void fillRandom(int* arr, const size_t size);

/**
 * @brief Создаёт копию массива
 * @param arr Исходный массив
 * @param size Размер массива
 * @return Полученный массив
 */
int* copyArray(const int* arr, const size_t size);

/**
 * @brief Заменяет максимальный по модулю отрицательный элемент массива нулем
 * @param copyArr Массив, в котором выполняется замена
 * @param size Размер массива
 * @return 1, если замена выполнена успешно, иначе 0
 */
int replaceMaxNegativeWithZero(int* copyArr, const size_t size);

/**
 * @brief Вставляет число К между всеми соседними элементами, которые имеют разные знаки
 * @param copyArr Исходный массив
 * @param size Размер массива
 * @return 1, если хотя бы один элемент был изменён, 0 если замены не произошло
 */
int insertKBetweenDifferentSigns(const int* copyArr, const size_t size);

/**
 * @brief Формирует новый массив A той же длины, что и D по правилу
 * @param copyArr Исходный массив D
 * @param size Размер массива
 * @return 1, если массив A успешно сформирован, 0 если не сформирован
 */
int fromDtoA(const int* copyArr, const size_t size);

/**
 * @brief RANDOM - заполнение массива случайными числами
 * @brief MANUAL - заполнение массива вручную.
 */
enum {RANDOM = 1, MANUAL};

/**
 * @brief Точка входа в программу.
 * @return 0, если программа выполнена корректно.
 */
int main(void)
{
    size_t size = getSize("Введите размер массива: ");
    int* arr = malloc(size * sizeof(int));
    checkMemoryAllocation(arr);
    printf("Выберите способ заполнения массива:\n"
           "%d - случайными числами в диапазоне [-100;200]\n"
           "%d - вручную\n"
           "Введите нужный номер заполнения: ",
           RANDOM, MANUAL);
    int choice = getValue();
    switch (choice)
    {
        case RANDOM:
            fillRandom(arr, size);
            break;
        case MANUAL:
            fillArray(arr, size);
            break;
        default:
            printf("Error! Неверный выбор.\n");
            free(arr);
            exit(1);
    }
    printf("\nИсходный массив:\n");
    printArray(arr, size);
    printf("\n1. Замена максимального по модулю отрицательного элемента нулем:\n");
    int* copyArr1 = copyArray(arr, size);
    if (replaceMaxNegativeWithZero(copyArr1, size))
    {
        printArray(copyArr1, size);
    }
    else
    {
        printf("Отрицательных элементов в массиве нет.\n");
    }
    free(copyArr1);
    printf("\n2. Вставка числа К между соседними элементами с разными знаками:\n");
    insertKBetweenDifferentSigns(arr, size);
    printf("\n3. Формирование массива A по правилу:\n");
    printf("Пожалуйста, введите значение k: ");
    fromDtoA(arr, size);
    free(arr);
    return 0;
}

/**
 * @brief Проверка выделения памяти
 * @param ptr Указатель на выделенную память
 */
void checkMemoryAllocation(void* ptr)
{
    if (ptr == NULL)
    {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }
}

int getValue(void)
{
    int value = 0;
    if (!scanf_s("%d", &value))
    {
        printf("Error, введено неверное значение!\n");
        exit(1);        
    }
    return value;
}

size_t getSize(char* message)
{
    printf("%s", message);
    int value = getValue();
    if (value <= 0)
    {
        printf("Error! Размер массива должен быть положительным числом.\n");
        exit(1);
    }
    return (size_t)value;
}

void fillArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Введите элемент массива arr[%zu] = ", i);
        arr[i] = getValue();
    }
}

void printArray(const int* arr, const size_t size)
{
    printf("[");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

void checkRange(const int start, const int end)
{
    if(start > end)
    {
        printf("Error! Начало диапазона должно быть меньше или равно концу.\n");
        exit(1);
    }
}

void fillRandom(int* arr, const size_t size)
{
    const int start = -100;
    const int end = 200;
    checkRange(start, end);
    
    printf("Заполнение массива случайными числами в диапазоне [%d; %d]\n", start, end);
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = (rand() % (end - start + 1)) + start;
    }
}

int* copyArray(const int* arr, const size_t size)
{
    int* copyArr = malloc(sizeof(int) * size);
    checkMemoryAllocation(copyArr);
    
    for (size_t i = 0; i < size; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}

int replaceMaxNegativeWithZero(int* copyArr, const size_t size)
{
    int maxAbsNegative = -1;
    size_t maxIndex = 0;
    int foundNegative = 0;
    
    for (size_t i = 0; i < size; i++)
    {
        if (copyArr[i] < 0)
        {
            maxAbsNegative = abs(copyArr[i]);
            maxIndex = i;
            foundNegative = 1;
            break;
        }
    }
    
    if (!foundNegative)
    {
        return 0;
    }
    
    for (size_t i = maxIndex + 1; i < size; i++)
    {
        if (copyArr[i] < 0)
        {
            int currentAbs = abs(copyArr[i]);
            if (currentAbs > maxAbsNegative)
            {
                maxAbsNegative = currentAbs;
                maxIndex = i;
            }
        }
    }
    
    copyArr[maxIndex] = 0;
    return 1;
}

int insertKBetweenDifferentSigns(const int* copyArr, const size_t size)
{
    if (size < 2)
    {
        printf("Массив слишком мал для вставки между элементами.\n");
        return 0;
    }
    printf("Введите значение K для вставки: ");
    int K = getValue();
    size_t insertCount = 0;
    for (size_t i = 0; i < size - 1; i++)
    {
        if ((copyArr[i] > 0 && copyArr[i + 1] < 0) || 
            (copyArr[i] < 0 && copyArr[i + 1] > 0))
        {
            insertCount++;
        }
    }
    
    if (insertCount == 0)
    {
        printf("Нет соседних элементов с разными знаками.\n");
        return 0;
    }
    size_t newSize = size + insertCount;
    int* newArr = malloc(newSize * sizeof(int));
    checkMemoryAllocation(newArr);
    size_t j = 0;
    for (size_t i = 0; i < size; i++)
    {
        newArr[j++] = copyArr[i];
        if (i < size - 1 && 
            ((copyArr[i] > 0 && copyArr[i + 1] < 0) || 
             (copyArr[i] < 0 && copyArr[i + 1] > 0)))
        {
            newArr[j++] = K;
        }
    }
    printf("Новый массив после вставки K=%d:\n", K);
    printArray(newArr, newSize);
    free(newArr);
    return 1;
}

int fromDtoA(const int* copyArr, const size_t size)
{
    if (size == 0)
    {
        printf("Массив D пуст!\n");
        return 0;
    }
    int k = getValue();
    if (k < 1 || k > (int)size)
    {
        printf("Error! k должно быть в диапазоне от 1 до %zu\n", size);
        return 0;
    }
    int* A = malloc(size * sizeof(int));
    checkMemoryAllocation(A);
    for (size_t i = 0; i < size; i++)
    {
        size_t index = i + 1;
        
        if (index <= (size_t)k)
        {
            A[i] = -(copyArr[i] * copyArr[i]);
        }
        else
        {
            A[i] = copyArr[i] - 1;
        }
    }
    printf("Массив A, сформированный по правилу (k=%d):\n", k);
    printArray(A, size);
    free(A);
    return 1;
}
