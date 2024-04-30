#include "TaOpenAdressingHashing.h"


unsigned short OpenAddressingHashTable::FNV1aHashFunction(const std::string& key) const { // FNV-1a хэш-функция
    unsigned int hash = 2166136261u; // Начальное значение хэша (просто число Фибоначчи) 
    for (char c : key) { // Для каждого символа в ключе
        hash ^= c; // Инвертируем хэш побитово
        hash *= 16777619u; // Умножаем на простое число Фибоначчи
    }
    return static_cast<unsigned short>(hash % TABLE_SIZE); // Возвращаем хэш, приведенный к шорту (хотя так т функция дает хэш в 32 бита аж), и берем его остаток от деления на размер таблицы (чтоб не вылезти за границы)
}

unsigned short OpenAddressingHashTable::JankinsHashFunction(const std::string& key) {
    unsigned short hash = 0;
    for (char c : key) {
        hash = (hash * 31 + c) % TABLE_SIZE;
    }
    return hash;
}

unsigned short OpenAddressingHashTable::linearProbe(unsigned short index, unsigned short probe) const { // Линейное пробирование
    return (index + probe) % TABLE_SIZE; // Просто прибавляем пробу к индексу и берем остаток от деления на размер таблицы
}

unsigned short OpenAddressingHashTable::quadraticProbe(unsigned short index, unsigned short probe) const { // Квадратичное пробирование
    return (index + probe * probe) % TABLE_SIZE; // Прибавляем к индексу квадрат пробы и берем остаток от деления на размер таблицы
}

template<typename Func> // Шаблон для измерения времени выполнения функции 
void OpenAddressingHashTable::measureExecutionTime(Func&& func) { // Принимает функцию, которую надо выполнить
    auto start = std::chrono::high_resolution_clock::now(); // Записывает время начала выполнения
    func(); // Выполняет функцию
    auto end = std::chrono::high_resolution_clock::now(); // записывает время окончания выполнения
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start); // Считает разницу 
    exec_time = static_cast<unsigned int>(duration.count()); // Записывает время выполнения в переменную
}

OpenAddressingHashTable::OpenAddressingHashTable(unsigned short& size) { // Конструктор класса
    measureExecutionTime([&]() {
    TABLE_SIZE = size; // Копируем размер таблицы
    table = new Entry[TABLE_SIZE]; // Создаем таблицу динамически с нужным размерчиком
    });
}

OpenAddressingHashTable::~OpenAddressingHashTable() { // Деструктор класса
    
    delete[] table; // Сносит после себя динамическую память 
    
}

void OpenAddressingHashTable::UseQuadraticProbe(bool mode) // Устанавливает режим для разрешения коллизий
{
    measureExecutionTime([&]() {
        isLinearProbe = !mode; // Просто меняет флаг на инвертированный переданный, true - линейное пробирование, false - квадратичное
        });
}

bool OpenAddressingHashTable::insert(const std::string& str, const unsigned short& num) { // Вставка записи в таблицу
    unsigned short index = FNV1aHashFunction(str); // Получаем индекс куда писать запись в таблицу через хэш-функцию 
    //unsigned short index = JankinsHashFunction(str); // Получаем индекс куда писать запись в таблицу через хэш-функцию 
    unsigned short probe = 0; // Кол-во проб, изначально 0
    bool inserted = false; // Булевая, нужна для проброса результата вывода через темплейт

    measureExecutionTime([&]() { // Темплейт под вермячко

        switch (table[index].occupied) {
        case false: {
            //table[index].key.str = str; // Пишем в нее ФИО
            table[index].occupied = true; // Помечаем ячейку как занятую
            table[index].key.str = std::move(str);
            table[index].key.num = num; // Пишем в ячейку оценку
            inserted = true; // Помечаем, что вставка прошла успешно
            break;
        }
        case true: {
            switch (isLinearProbe) {
            case true: { // Если же ячейка занята, и метод разрешения коллизий выбран как линейное пробирование
                while (probe < MAX_PROBES) { // Пока не упремся в лимит проб
                        index = linearProbe(index, probe); // Получаем новый индекс через линейное пробирование
                        if (!table[index].occupied) { // Если ячейка свободна
                            //table[index].key.str = str; // Пишем в нее ФИО
                            table[index].occupied = true;
                            table[index].key.str = std::move(str);
                            table[index].key.num = num; // Пишем в ячейку оценку
                            // Помечаем ячейку как занятую
                            inserted = true; // Помечаем, что вставка прошла успешно
                            break;
                        }
                        probe++; // Иначе увеличиваем пробу и на след заход
                }
            break;
            }
            case false: { // А если решаем квардратичным пробированием
                while (probe < MAX_PROBES) {  // Все аналогично первому, но вместо линейного пробирования используем квадратичное
                        index = quadraticProbe(index, probe);
                        if (!table[index].occupied) {
                            table[index].occupied = true; // Помечаем ячейку как занятую
                            table[index].key.str = std::move(str);
                            table[index].key.num = num; // Пишем в ячейку оценку
                            inserted = true; // Помечаем, что вставка прошла успешно
                            break;
                        }
                        probe++;
                }
            break;
            }
            }
        break;
        }
        }
        });

    return inserted; // Иначе хвастаемся какие мы молодцы
}

bool OpenAddressingHashTable::insert(const Student& input)
{
    return OpenAddressingHashTable::insert(input.str, input.num); // Перегружаем метод, чтоб тот мог принимать данные структурой студента
}

Student OpenAddressingHashTable::search(unsigned short index) { // Поиск записи по индексу
    Student result; // Создаем структуру, которую будем отдавать
    measureExecutionTime([&]() { // Временищще
        if (index >= 0 && index < TABLE_SIZE && table[index].occupied) { // Если индекс в пределах таблицы и в ячейке чет да есть
            result = table[index].key; // Вносим в студента
        }
        else {
            result = Student{ "", 0 }; // Иначе пустую структуру даем
        }
        });
    return result; // Отдаем результат
}

std::vector<Student> OpenAddressingHashTable::getHashTable() { // Передача таблицы вектором
    std::vector<Student> hashTable; // Создаем вектор массива студентов
    measureExecutionTime([&]() { // Часики
        for (unsigned short i = 0; i < TABLE_SIZE; i++) { // Проходимся по всему массиву
            if (table[i].occupied) { // Если ячейка занята
                hashTable.push_back(table[i].key); // Пушим ее
            }
            else { 
                hashTable.push_back({ "", 0 }); // Иначе пушим пустую структуру
            }
        }
        });
    return hashTable; // Возвращаем вектор
}

unsigned int OpenAddressingHashTable::getExecutionTime() const { // Получение времени выполнения
    return exec_time; // Попросил - получил
}

bool OpenAddressingHashTable::Remove(unsigned short index) { // Удаление записи по индексу
    bool success = false;

    measureExecutionTime([&]() {
        if (index >= 0 && index < TABLE_SIZE && table[index].occupied) {
            table[index].occupied = false; // Помечаем ячейку как свободную
            table[index].key = Student{ "", 0 }; // Обнуляем данные в ячейке
            success = true; // Если запись удалена, то возвращаем тру
        }
        });

    return success;
}
