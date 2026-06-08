#pragma once
#include <initializer_list>
#include <string>
#include <stdexcept>
#include <cstddef>

class Deque
{
private:
    int* m_elements;
    std::size_t m_count;

public:
    Deque();
    Deque(const std::initializer_list<int> items);
    Deque(const Deque& other);
    Deque(Deque&& other);
    ~Deque();

    std::string to_string() const;
    std::size_t get_size() const;
    bool is_empty() const;

    void push_front(const int value);
    void push_back(const int value);
    int pop_front();
    int pop_back();
    int& front();
    const int& front() const;
    int& back();
    const int& back() const;

    Deque& operator=(const Deque& other);
    Deque& operator=(Deque&& other);
};
