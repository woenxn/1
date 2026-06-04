#pragma once
#include <initializer_list>
#include <string>
#include <stdexcept>

class Deque
{
private:
    int* m_elements;
    size_t m_count; 

public:
    Deque();
    Deque(const std::initializer_list<int> items);
    Deque(const Deque& other);
    Deque(Deque&& other);
    ~Deque();

    std::string to_string() const;
    size_t get_size() const;
    bool is_empty() const;

    void push_front(int value);
    void push_back(int value);
    int pop_front();
    int pop_back();
    int& front();
    const int& front() const;
    int& back();
    const int& back() const;

    int& operator[](size_t index);
    const int& operator[](size_t index) const;

    Deque& operator=(const Deque& other);
    Deque& operator=(Deque&& other);

    friend std::ostream& operator<<(std::ostream& os, const Deque& d);
    friend std::istream& operator>>(std::istream& is, Deque& d);
};
