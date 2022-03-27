#pragma once
using namespace std; 

/// <summary>
/// ��������� �������� �����
/// </summary>
struct Node                             
{
    /// <summary>
    /// �������� �������� ��������
    /// </summary>
    int _date;

    /// <summary>
    /// ��������� �� ��������� �������
    /// </summary>
    Node* _next;

    /// <summary>
    /// ��������� �� ���������� �������
    /// </summary>
    Node* _previous;
};

class List
{
private:
    /// <summary>
    /// ����������� ��������� � List
    /// </summary>
    int _length;

    /// <summary>
    /// ��������� �� 0-�� �������
    /// </summary>
    Node* _head;

    /// <summary>
    /// �������� �� ��������� �������
    /// </summary>
    Node* _tail;

public:
    /// <summary>
    /// �� ��������� ����� ��������� nullptr ������ �� ��������� 1
    /// </summary>
    List() : _head(nullptr), _tail(nullptr), _length(1) {};
    ~List();

    /// <summary>
    /// ���������� ������ ��������
    /// </summary>
    /// <param name="valueToPush">����������� ��������</param>
    void AddNode(int valueToPush);

    /// <summary>
    /// ������� � �����
    /// </summary>
    /// <param name="valueToPush">����������� ��������</param>
    void PushBack(int valueToPush);

    /// <summary>
    /// �������� �� �������
    /// </summary>
    /// <param name="index">������ ��������</param>
    void DelteNode(int index);

    /// <summary>
    /// ������� ������
    /// </summary>
    /// <param name="valueToPush">����������� ��������</param>
    void PushForward(int valueToPush);

    /// <summary>
    ///  ������� ����� ��������
    /// </summary>
    /// <param name="index">������ ����� �������� ��������� �������</param>
    /// <param name="valueToPush">����������� ��������</param>
    void PushAfterNode(int index, int valueToPush);

    /// <summary>
    /// ������� ����� ���������
    /// </summary>
    /// <param name="index">������ ����� ������� ��������� �������</param>
    /// <param name="valueToPush">����������� ��������</param>
    void PushBeforeNode(int index, int valueToPush);

    /// <summary>
    /// ����������
    /// </summary>
    void Sort();

    /// <summary>
    /// ���� ��������
    /// </summary>
    /// <param name="value">��������</param>
    int LinearSearch(int value);

    /// <summary>
    /// ���������� ��������� �� ������ ������
    /// </summary>
    /// <returns>��������� �� ������ ������</returns>
    Node* GetHead()
    {
        return this->_head;
    }

    /// <summary>
    /// ���������� ������ �����
    /// </summary>
    /// <returns>���-�� ���������</returns>
    int GetLength()
    {
        return this->_length;
    }

    /// <summary>
    /// ����������� ������ �� �������
    /// </summary>
    void SetLength()
    {
        this->_length++;
    }
};
