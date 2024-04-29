#pragma once
#include <list>
#include <chrono>
#include <string>
using namespace std;

class Hash
{
private:
    unsigned short BUCKET; // Кол-во ячеек в хеш-таблице
    bool mode; // Режим работы (по умолчанию деление - false, умножение - true)
    unsigned int exec_time = NULL; // Время исполнения, возврашает время в наносекундах
    list<pair<string, unsigned short>>* table; // Двусвязный список указателей на пары ключ-значение
    unsigned short const hashFunctionDivision(string key); // Хеш-функция деления
    unsigned short const hashFunctionMultiplication(string key); // Хеш-функция умножения

    // Шаблон функции для измерения времени исполнения, перекочевал с той лабы, пашет на ура
    template<typename Func>
    void measureExecutionTime(Func&& func);

public:
    Hash(unsigned short V); // Конструктор класса
    void setModeDivision(); // Устанавливает режим работы класса через хеш-функцию деления
    void setModeMultiplication(); // Устанавливает режим работы класса через хеш-функцию умножения

    void insertItem(string key, unsigned short data); // Добавление элемента в хеш-таблицу, принимает ключ и данные
    void deleteItem(string key); // Удаление элемента из хеш-таблицы, принимает ключ элемента, который над валить
    unsigned short searchItem(string key); // Ищет элемент в хеш-таблице по ключу и возвращает данные
    string dehashItem(unsigned short bucket); // Возвращает элементы из ячейки хеш-таблицы 
    string displayHash();  // Выводит хеш-таблицу в виде большой строчки


    unsigned int getExecutionTime(); // Выводит время исполнения, работает для всех (публичных) методов класса

    ~Hash(); // Деструктор класса, освобождает память нашу динамическую
};