#include <iostream>
#include "NodeAndList.h"


void ForDeleteNode(Node* pointerNode, int index)
{
    for (int i = 0; i < index; i++)
    {
        pointerNode = pointerNode->_next;
    }
    pointerNode->_next->_previous = pointerNode->_previous;
    pointerNode->_previous->_next = pointerNode->_next;
    delete pointerNode;
}

List::~List()                           
{
    while (_head)                     
    {
        _tail = _head->_next;            
        delete _head;                   
        _head = _tail;                   
    }
}

void List::PushForward(int valueToPush)
{
    if (_length == 0)
    {
        AddNode(valueToPush);
        return;
    }
    _head->_previous = new Node;
    _head->_previous->_next = _head;
    _head = _head->_previous;
    _head->_date = valueToPush;
    _length++;
}


void List::PushBack(int valueToPush)
{
    AddNode(valueToPush);
}


void List::AddNode(int valueToPush)
{
   Node* temp = new Node;               
   temp->_next = nullptr;
   temp->_date = valueToPush;                         

   if (_head != nullptr)
   {
        temp->_previous = _tail;               
        _tail->_next = temp;               
        _tail = temp;                     
   }
   else
   {
        temp->_previous = nullptr;
        _head = _tail = temp;              
   } 
}

void List::DelteNode(int index)
{
    if (_head == _tail)
    {
        delete _head;
    }
    else if (index == 0)
    { 
        Node* pointerNode = _head;
        pointerNode->_next->_previous = nullptr;
        _head = pointerNode->_next;
        delete pointerNode;
    }
    else if (index == _length - 1)
    {
        Node* pointerNode = _tail;
        pointerNode->_previous->_next = nullptr;
        _tail = pointerNode->_previous;
        delete pointerNode;
    }
    else if (index < _length - 1)
    {
        Node* pointerNode = _head;
        ForDeleteNode(pointerNode, index);
    }
    else
    {
        Node* pointerNode = _tail;
        ForDeleteNode(pointerNode, _length - index);
    }
    _length--;
}

void List::PushAfterNode(int index, int valueToPush) 
{
   
    if (index == _length - 1)
    {
        AddNode(valueToPush);
    }
    else
    {
        PushBeforeNode(index-1, valueToPush);
    }
}

void List::PushBeforeNode(int index, int valueToPush)
{
    if (index == 0)
    {
        PushForward(valueToPush);
    }
    else if (index > _length)
    {
        //Слишком большой индекс, элемент добавлен в конец";
         PushBack(valueToPush);
         _length++;
    }
    else
    {
        Node* pointerNode = _head;
        for (int i = 0; i < index; i++)
        {
            if (index > _length)
            {
                break;
            }
            pointerNode = pointerNode->_next;
        }
            pointerNode->_previous->_next = new Node;
            pointerNode->_previous->_next->_date = valueToPush;
            pointerNode->_previous->_next->_next = pointerNode;
            pointerNode->_previous->_next->_previous = pointerNode->_previous;
            pointerNode->_previous = pointerNode->_previous->_next;
            
            _length++;

    }
}

void List::Sort()
{
    Node* pointerNode = _head;
    for (int i = 0; i < _length - 1; i++)
    {
        for (int j = 0; j < _length - 2; j++)
        {
            if (pointerNode->_date > pointerNode->_next->_date)
            {
                swap(pointerNode->_date, pointerNode->_next->_date);
            }
            else
            {
                pointerNode = pointerNode->_next;
            }
        }
        pointerNode = _head;
    }
}


int List::LinearSearch(int value)
{
    Node* pointerNode = _head;
    for (int i = 0; i < _length; i++)
    {
        if (pointerNode->_date == value)
        {
            return i;
            break;
        }
        else if (pointerNode == _tail)
        {
            return -1;
            break;
        }
        else 
        {
            pointerNode = pointerNode->_next;
        }
    }
    return 0;
}