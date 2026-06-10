#include <iostream>
#include <string>
#include <cstdlib>
#include "deque.h"

using namespace std;

/**
 * @brief Действия, которые можно выполнить с деком
 * Используются в меню для выбора операции
 */
enum Actions
{
    PUSH_FRONT = 1, PUSH_BACK, POP_FRONT, POP_BACK, FRONT, BACK, PRINT
};

/**
 * @brief Выводит сообщение об ошибке и завершает программу
 * @param text Текст сообщения об ошибке
 */
void ERROR(const string& text);

/**
 * @brief Считывает с клавиатуры целое число
 * @return Введённое число
 * @note При ошибке ввода (если не число) вызывает ERROR()
 */
int get_choice();

/**
* @brief Точка входа в программу
* @return Если программа выполнена корректно - 0, иначе 1
*/
int main()
{
    Deque collection;
    cout << "Specify the initial number of deck elements: ";
    int n = get_choice();
    if (n < 0)
        ERROR("Error: the number of elements cannot be negative.");

    if (n > 0)
    {
        cout << "Enter " << n << " deque elements: " << endl;
        for (size_t i = 0; i < static_cast<size_t>(n); ++i)
        {
            int val = get_choice();
            collection.push_back(val);
        }
    }

    cout << "The original deque: " << collection.to_string() << endl;

    cout << "Choose an action with a deque:" << endl
        << PUSH_FRONT << " - Add to beginnig" << endl
        << PUSH_BACK << " - Добавить в конец" << endl
        << POP_FRONT << " - Удалить из начала" << endl
        << POP_BACK << " - Удалить из конца" << endl
        << FRONT << " - Показать первый элемент" << endl
        << BACK << " - Показать последний элемент" << endl
        << PRINT << " - Вывести весь дек" << endl;

    cout << "Your choice: ";
    int choice = get_choice();

    try
    {
        switch (choice)
        {
        case PUSH_FRONT:
        {
            cout << "Enter the value to add to the beginning: ";
            int val = get_choice();
            collection.push_front(val);
            cout << "After push_front: " << collection.to_string() << endl;
            break;
        }
        case PUSH_BACK:
        {
            cout << "Введите значение для добавления в конец: ";
            int val = get_choice();
            collection.push_back(val);
            cout << "После push_back: " << collection.to_string() << endl;
            break;
        }
        case POP_FRONT:
        {
            int val = collection.pop_front();
            cout << "Удалено из начала: " << val << endl;
            cout << "Текущий дек: " << collection.to_string() << endl;
            break;
        }
        case POP_BACK:
        {
            int val = collection.pop_back();
            cout << "Удалено из конца: " << val << endl;
            cout << "Текущий дек: " << collection.to_string() << endl;
            break;
        }
        case FRONT:
        {
            cout << "Первый элемент: " << collection.front() << endl;
            break;
        }
        case BACK:
        {
            cout << "Последний элемент: " << collection.back() << endl;
            break;
        }
        case PRINT:
        {
            cout << "Дек: " << collection.to_string() << endl;
            break;
        }
        default:
            ERROR("Ошибка: Неверный выбор пункта меню.");
        }
    }
    catch (const exception& e)
    {
        cout << "Ошибка! " << e.what() << endl;
    }

    return 0;
}


void ERROR(const string& text)
{
    cerr << text << endl;
    exit(1);
}


int get_choice()
{
    int number = 0;
    cin >> number;
    if (cin.fail())
    {
        ERROR("Ошибка ввода");
    }
    return number;
}
