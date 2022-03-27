//Лабораторная работа 2            Линейный двусвязный список
#include "NodeAndList.h"
#include <iostream>
#include <string>
using namespace std;

/// <summary>
/// Функция, которая реализует красивый ввод ЛЮБОЙ
/// целочисленной переменной в этой програме, и спасает нас от миллиона дублей
/// </summary>
/// <param name="iputInformation">Текстовое поле, перед ввод, 
/// спрашиваем, что пользователь должен ввести</param>
/// <param name="value">ВВодимая переменная</param>
/// <returns>Уже инициализированная переменная</returns>
int Input(int& value, string iputInformation='\0')
{
    cout << iputInformation;

    string string;
    cin >> string;
    try 
    {
        value = stoi(string);
    }
    catch (std::exception& e) 
    {
        Input(value, "Введено некоректное значение\nВведите значение заново: ");
    }
    cout << endl;
    return value;
}

/// <summary>
/// Приветствие
/// </summary>
void Help()
{
    cout << "Для проверки на созданность листа, введите 1." << endl;
    cout << "Для добавления элемента в конец листа, введите 2." << endl;
    cout << "Для удаления элемента, введите 3." << endl;
    cout << "Для добавления элемента в начало листа, введите 4." << endl;
    cout << "Для вставки после указанного индекса, введите 5." << endl;
    cout << "Для вставки перед указанным индексом, введите 6." << endl;
    cout << "Сортировка, введите 7." << endl;
    cout << "Для линейного поиска, введите 8." << endl;
    cout << "Показать лист, введите 9." << endl;
}

/// <summary>
/// Функция вывода листа
/// </summary>
/// <param name="node">указатель на лист</param>
void ShowList(List* node)
{
    Node* temp = node->GetHead();
    while (temp != nullptr)
    {
        cout << temp->_date << " ";
        temp = temp->_next;
    }
    cout << endl;
}

/// <summary>
/// Реализация меню
/// </summary>
/// <param name="operationCode">индефикатор операции</param>
/// <param name="list">указатель на лист</param>
void AnalizeOperationCode(int operationCode, List* list)
{
    switch (operationCode)
    {
        
        case 1:
        {
            
            if (list == nullptr)
            {
                list = new List;
                cout << "Лист создан успешно!" << endl;
            }
            else
            {
                cout << "Лист уже был создан!" << endl;
            }
            break;
        }
        
        case 2:
        {
            int valueToPush = Input(valueToPush, "Введите добавляемое в конец значение:"); 
            list->PushBack(valueToPush);
            break;
        }
        
        case 3: 
        {
            int index = Input(index, "Введите удаляемый индекс:");
            list->DelteNode(index);
            break;
        }
        
        case 4:
        {
            int valueToPush = Input(valueToPush, "Введите вставляемое впереди "); 
            list->PushForward(valueToPush);
            break;
        }
        
        case 5:
        {
            int index = Input(index, "Введите индекс после которого вставляем элемент:");
            int valueToPush = Input(valueToPush, "Введите сам элемент:");
            list->PushBeforeNode(index+1, valueToPush);
            break;
        }

        case 6:
        {
            int index = Input(index, "Введите индекс перед которым вставляем элемент:");
            int valueToPush = Input(valueToPush, "Введите сам элемент:");
            list->PushBeforeNode(index, valueToPush);
            break;
        }
        
        case 7:
        {
            if (list == nullptr || list->GetLength() < 2)
            {
                cout << "Лист не создан или имеет меньше двух элементов!" << endl;
            }
            else
            {
                list->Sort();
            }
            break;
        }
            
        case 8:
        {
            int value = Input(value, "Введите переменную, которую ищем:");
            if (list->LinearSearch(value) == -1)
            {
                cout << "Элемент не найден" << endl;
            }
            else
            {
                cout << list->LinearSearch(value) << endl;
            }
            break;
        }
        
        case 9:
        {
            ShowList(list);
            break;
        }

        default:
            Help();
            break;
    }
}



int main()
{
    setlocale(LC_ALL, "ru");
    List* list1 = new List;

    int operationCode;
    do
    {
        Help();
        Input(operationCode, "Введите код операции_ ");
        AnalizeOperationCode(operationCode, list1);
    } while (!(operationCode < 1 || operationCode > 9));
    cout << "Введена неверная операция, программа безопасно завершилась" << endl;

    return 0;
}