/**
 * @class Deque
 * @brief двусторонняя очередь на динамическом массиве,
 *        добавление и удаление с обоих концов
 */
class Deque
{
public:
    /** @brief создаёт пустую очередь
    */
    Deque();

    /** @brief создаёт очередь из списка элементов
    * @param items список элементов
    */
    Deque(const std::initializer_list<int> items);

    /** @brief копирующий конструктор
    * @param other копирующий элемент
    */
    Deque(const Deque& other);

    /** @brief перемещающий конструктор
    * @param other перемещаемый обьект
    */
    Deque(Deque&& other);

    /** @brief освобождает память
    */
    ~Deque();

    /** @return строка вида "[a, b, ...]"
    */
    std::string to_string() const;

    /** @return количество элементов
    */
    std::size_t get_size() const;

    /** @return true, если очередь пуста
    */
    bool is_empty() const;

    /** @brief добавляет элемент в начало
    * @param value добавляемый элемент
    */
    void push_front(const int value);

    /** @brief добавляет элемент в конец
    * @param value добавляемый элемент
    */

    void push_back(const int value);

    /** @brief удаляет и возвращает первый элемент
    * @return значение удаленного элемента
    */
    int pop_front();

    /** @brief удаляет и возвращает последний элемент
    * @return значение удаленного элемента
    */
    int pop_back();

    /** @return ссылка на первый элемент
    */
    int& front();

    /** @return константная ссылка на первый элемент
    */
    const int& front() const;

    /** @return ссылка на последний элемент
    */
    int& back();

    /** @return константная ссылка на последний элемент
    */
    const int& back() const;

    /** @brief копирующее присваивание
    * @param other присваиваемый обьект
    * @return ссылка на текущий обьект
    */
    Deque& operator=(const Deque& other);

    /** @brief перемещающее присваивание
    * @param other перемещаемый обьект
    * @return ссылка на текущий обьект
    */
    Deque& operator=(Deque&& other);
};
