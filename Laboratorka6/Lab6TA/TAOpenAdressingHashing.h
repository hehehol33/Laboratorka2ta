#pragma once
#ifndef TAOPENADDRESSINGHASHING_H
#define TAOPENADDRESSINGHASHING_H


#include <string>
#include <vector>
#include <chrono>
#include <cstdint>

struct Student {
    std::string str;
    unsigned short num;
};

class OpenAddressingHashTable {
private:
    unsigned short TABLE_SIZE;
    static const unsigned short MAX_PROBES = 3;
    bool isLinearProbe = true;
    unsigned int exec_time = NULL;

    struct Entry {
        Student key;
        bool occupied = false;
    };

    Entry* table;
    unsigned short JankinsHashFunction(const std::string& key); // Хэш-функция Дженкинса, быстрая и равномерная, принимает ФИО и возвращает хэш
    unsigned short FNV1aHashFunction(const std::string& key) const; // Хэш-функция вместо Дженкинса, тож весьма быстра, но равномернее и дает меньше коллизий, принимает ФИО и возвращает хэш
    unsigned short linearProbe(unsigned short index, unsigned short probe) const; // Линейное пробирование, возвращает новый индекс (он же хэш) для записи в случае коллизии
    unsigned short quadraticProbe(unsigned short index, unsigned short probe) const;


    template<typename Func>
    void measureExecutionTime(Func&& func);

public:
    OpenAddressingHashTable(unsigned short& size);
    ~OpenAddressingHashTable();

    bool insert(const std::string& str, const unsigned short& num);
    Student search(unsigned short index);
    std::vector<Student> getHashTable();
    bool Remove(unsigned short index);
    unsigned int getExecutionTime() const;
};

#endif /* TAOPENADDRESSINGHASH_H */
