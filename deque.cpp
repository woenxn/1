#include "deque.h"
#include <sstream>

Deque::Deque() : m_elements(nullptr), m_count(0) {}

Deque::Deque(const std::initializer_list<int> items)
    : m_elements(nullptr), m_count(items.size())
{
    if (m_count > 0)
    {
        m_elements = new int[m_count];
        std::size_t idx = 0;
        for (const int& val : items)
            m_elements[idx++] = val;
    }
}

Deque::Deque(const Deque& other)
    : m_elements(nullptr), m_count(other.m_count)
{
    if (m_count > 0)
    {
        m_elements = new int[m_count];
        for (std::size_t i = 0; i < m_count; ++i)
            m_elements[i] = other.m_elements[i];
    }
}

Deque::Deque(Deque&& other)
    : m_elements(other.m_elements), m_count(other.m_count)
{
    other.m_elements = nullptr;
    other.m_count = 0;
}

Deque::~Deque()
{
    delete[] m_elements;
}

std::string Deque::to_string() const
{
    if (is_empty())
        return "Empty";

    std::stringstream ss;
    for (std::size_t i = 0; i < m_count; ++i)
    {
        ss << m_elements[i];
        if (i < m_count - 1)
            ss << " ";
    }
    return ss.str();
}

std::size_t Deque::get_size() const
{
    return m_count;
}

bool Deque::is_empty() const
{
    return m_count == 0;
}

void Deque::push_front(int value)
{
    int* temp = new int[m_count + 1];
    for (std::size_t i = 0; i < m_count; ++i)
        temp[i + 1] = m_elements[i];
    temp[0] = value;
    delete[] m_elements;
    m_elements = temp;
    ++m_count;
}

void Deque::push_back(int value)
{
    int* temp = new int[m_count + 1];
    for (std::size_t i = 0; i < m_count; ++i)
        temp[i] = m_elements[i];
    temp[m_count] = value;
    delete[] m_elements;
    m_elements = temp;
    ++m_count;
}

int Deque::pop_front()
{
    if (is_empty())
        throw std::out_of_range("Deque is empty: cannot pop_front");

    int result = m_elements[0];
    if (m_count == 1)
    {
        delete[] m_elements;
        m_elements = nullptr;
        m_count = 0;
    }
    else
    {
        int* temp = new int[m_count - 1];
        for (std::size_t i = 1; i < m_count; ++i)
            temp[i - 1] = m_elements[i];
        delete[] m_elements;
        m_elements = temp;
        --m_count;
    }
    return result;
}

int Deque::pop_back()
{
    if (is_empty())
        throw std::out_of_range("Deque is empty: cannot pop_back");

    int result = m_elements[m_count - 1];
    if (m_count == 1)
    {
        delete[] m_elements;
        m_elements = nullptr;
        m_count = 0;
    }
    else
    {
        int* temp = new int[m_count - 1];
        for (std::size_t i = 0; i < m_count - 1; ++i)
            temp[i] = m_elements[i];
        delete[] m_elements;
        m_elements = temp;
        --m_count;
    }
    return result;
}

int& Deque::front()
{
    if (is_empty())
        throw std::out_of_range("Deque is empty: no front element");
    return m_elements[0];
}

const int& Deque::front() const
{
    if (is_empty())
        throw std::out_of_range("Deque is empty: no front element");
    return m_elements[0];
}

int& Deque::back()
{
    if (is_empty())
        throw std::out_of_range("Deque is empty: no back element");
    return m_elements[m_count - 1];
}

const int& Deque::back() const
{
    if (is_empty())
        throw std::out_of_range("Deque is empty: no back element");
    return m_elements[m_count - 1];
}

Deque& Deque::operator=(const Deque& other)
{
    if (this != &other)
    {
        delete[] m_elements;
        m_count = other.m_count;
        m_elements = (m_count > 0) ? new int[m_count] : nullptr;
        for (std::size_t i = 0; i < m_count; ++i)
            m_elements[i] = other.m_elements[i];
    }
    return *this;
}

Deque& Deque::operator=(Deque&& other)
{
    if (this != &other)
    {
        delete[] m_elements;
        m_elements = other.m_elements;
        m_count = other.m_count;
        other.m_elements = nullptr;
        other.m_count = 0;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Deque& d)
{
    os << d.to_string();
    return os;
}
