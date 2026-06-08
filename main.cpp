#include <iostream>
#include <string>
#include <cstdlib>
#include "deque.h"

using namespace std;

enum Actions
{
    PUSH_FRONT = 1, PUSH_BACK, POP_FRONT, POP_BACK, FRONT, BACK, PRINT
};

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

int main()
{
    Deque collection;
    cout << "Укажите начальное количество элементов дека: ";
    int n = get_choice();
    if (n < 0)
        ERROR("Ошибка: количество элементов не может быть отрицательным.");

    if (n > 0)
    {
        cout << "Введите " << n << " элементов дека: " << endl;
        for (size_t i = 0; i < static_cast<size_t>(n); ++i)
        {
            int val = get_choice();
            collection.push_back(val);
        }
    }

    cout << "Изначальный дек: " << collection.to_string() << endl;

    cout << "Выберите действие с деком:" << endl
         << PUSH_FRONT << " - Добавить в начало" << endl
         << PUSH_BACK  << " - Добавить в конец" << endl
         << POP_FRONT  << " - Удалить из начала" << endl
         << POP_BACK   << " - Удалить из конца" << endl
         << FRONT      << " - Показать первый элемент" << endl
         << BACK       << " - Показать последний элемент" << endl
         << PRINT      << " - Вывести весь дек" << endl;

    cout << "Ваш выбор: ";
    int choice = get_choice();

    try
    {
        switch (choice)
        {
        case PUSH_FRONT:
        {
            cout << "Введите значение для добавления в начало: ";
            int val = get_choice();
            collection.push_front(val);
            cout << "После push_front: " << collection.to_string() << endl;
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
