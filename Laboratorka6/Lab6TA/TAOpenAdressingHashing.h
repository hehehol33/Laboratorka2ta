#pragma once
#ifndef TAOPENADDRESSINGHASHING_H // Защита от дурака, дабы дважды не включался файл
#define TAOPENADDRESSINGHASHING_H

// Подключение зависимостей

#include <string>
#include <vector>
#include <chrono>
#include <cstdint>

struct Student { // Структура студента, содержащая ФИО и оценку
    std::string str; // По умолчанию пустая строка
    unsigned short num; // По умолчанию пусто
};

class OpenAddressingHashTable { // Сам класс хэш-таблицы с открытой адресацией
private:
    unsigned short TABLE_SIZE; // Размер таблицы, задается в конструкторе
    static const unsigned short MAX_PROBES = 5; // Максимальное количество проб при коллизии
    bool isLinearProbe = false; // Флаг, указывающий на метод разрешения коллизий, true - линейное пробирование, false - квадратичное
    unsigned int exec_time = NULL; // Время выполнения последней операции

    struct Entry { // Структура записи в таблице
        Student key; // Ключ записи, с которого для генерации хэша используем только ФИО
        bool occupied = false; // Флаг, указывающий на то, что ячейка занята или свободна
    };

    Entry* table; // Сама таблица, через указатели иб создается динамически
    unsigned short JankinsHashFunction(const std::string& key); // Хэш-функция Дженкинса, быстрая и равномерная, принимает ФИО и возвращает хэш, пока не используется за ненадобностью
    unsigned short FNV1aHashFunction(const std::string& key) const; // Хэш-функция вместо Дженкинса, тож весьма быстра, но равномернее и дает меньше коллизий, принимает ФИО и возвращает хэш
    unsigned short linearProbe(unsigned short index, unsigned short probe) const; // Линейное пробирование, возвращает новый индекс (он же хэш) для записи в случае коллизии
    unsigned short quadraticProbe(unsigned short index, unsigned short probe) const; // Квадратичное пробирование, аналогично


    template<typename Func> // Класический кочующий с лабы в лабу шаблон для измерения времени выполнения функции
    void measureExecutionTime(Func&& func);

public:
    OpenAddressingHashTable(unsigned short& size);
    ~OpenAddressingHashTable();
    void UseQuadraticProbe(bool mode); // Установка квадратичного пробирования, true - квадратичное, false - линейное
    bool insert(const std::string& str, const unsigned short& num); // Вставка записи в таблицу, принимает ФИО и оценку, возвращает true если запись вставлена успешно, и false если у нас ошибка
    bool insert(const Student& input); // Тож самое, ток принимает структуру студента
    Student search(unsigned short index); // Поиск записи по индексу, возвращает запись, если она найдена, иначе пустую запись {"", null}
    std::vector<Student> getHashTable(); // Возвращает хэш таблицу для вывода в виде записи. Вектор чтоб т-щу фронтенду не заниматься любовью с динамической памятью. По сути массив структур студентов, если запись есть - выдает ее, если нет - {"", null}
    bool Remove(unsigned short index); // Удаление записи по индексу, возвращает true если запись удалена успешно, иначе false
    unsigned int getExecutionTime() const; // Возвращает время выполнения последней операции в наносекундах
};

#endif /* TAOPENADDRESSINGHASH_H */
