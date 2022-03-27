#pragma once
using namespace std; 

/// <summary>
/// Структура элемента листа
/// </summary>
struct Node                             
{
    /// <summary>
    /// Числовое значение элемента
    /// </summary>
    int _date;

    /// <summary>
    /// Указатель на следующий элемент
    /// </summary>
    Node* _next;

    /// <summary>
    /// указатель на предыдущий элемент
    /// </summary>
    Node* _previous;
};

class List
{
private:
    /// <summary>
    /// Колличество элементов в List
    /// </summary>
    int _length;

    /// <summary>
    /// Указатель на 0-ой элемент
    /// </summary>
    Node* _head;

    /// <summary>
    /// Укаатель на последний элемент
    /// </summary>
    Node* _tail;

public:
    /// <summary>
    /// По умолчанию задаём указатели nullptr длинна по умолчанию 1
    /// </summary>
    List() : _head(nullptr), _tail(nullptr), _length(1) {};
    ~List();

    /// <summary>
    /// Добавление одного элемента
    /// </summary>
    /// <param name="valueToPush">добавляемое значение</param>
    void AddNode(int valueToPush);

    /// <summary>
    /// вставка в конец
    /// </summary>
    /// <param name="valueToPush">добавляемое значение</param>
    void PushBack(int valueToPush);

    /// <summary>
    /// Удаление по индексу
    /// </summary>
    /// <param name="index">индекс удаления</param>
    void DelteNode(int index);

    /// <summary>
    /// вставка вперед
    /// </summary>
    /// <param name="valueToPush">добавляемое значение</param>
    void PushForward(int valueToPush);

    /// <summary>
    ///  Вставка после элемента
    /// </summary>
    /// <param name="index">индекс после которого вставляем элемент</param>
    /// <param name="valueToPush">вставляемое значение</param>
    void PushAfterNode(int index, int valueToPush);

    /// <summary>
    /// Вставка перед элементом
    /// </summary>
    /// <param name="index">индекс перед которым вставляем элемент</param>
    /// <param name="valueToPush">вставляемое значение</param>
    void PushBeforeNode(int index, int valueToPush);

    /// <summary>
    /// Сортировка
    /// </summary>
    void Sort();

    /// <summary>
    /// Ищем значение
    /// </summary>
    /// <param name="value">значение</param>
    int LinearSearch(int value);

    /// <summary>
    /// Возвращает указатель на голову списка
    /// </summary>
    /// <returns>указатель на голову списка</returns>
    Node* GetHead()
    {
        return this->_head;
    }

    /// <summary>
    /// Возвращает длинну листа
    /// </summary>
    /// <returns>кол-во элементов</returns>
    int GetLength()
    {
        return this->_length;
    }

    /// <summary>
    /// Увеличивает длинну на еденицу
    /// </summary>
    void SetLength()
    {
        this->_length++;
    }
};
