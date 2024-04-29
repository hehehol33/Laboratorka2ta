#include "TASimpleHash.h"


Hash::Hash(unsigned short b)
{
    this->BUCKET = b;
    this->mode = false; // default mode is division
    table = new list<pair<string, unsigned short>>[BUCKET];
}

void Hash::insertItem(string key, unsigned short data)
{
    measureExecutionTime([&]() {
        unsigned short index;
        if (mode) {
            index = hashFunctionMultiplication(key);
        }
        else {
            index = hashFunctionDivision(key);
        }
        table[index].push_back(make_pair(key, data));
        });
}

void Hash::deleteItem(string key)
{
    measureExecutionTime([&]() {
        // get the hash index of key
        unsigned short index;
        if (mode) {
            index = hashFunctionMultiplication(key);
        }
        else {
            index = hashFunctionDivision(key);
        }

        // find the key in (index)th list
        list<pair<string, unsigned short>>::iterator i;
        for (i = table[index].begin();
            i != table[index].end(); i++) {
            if (i->first == key)
                break;
        }

        // if key is found in hash table, remove it
        if (i != table[index].end())
            table[index].erase(i);
        });
}

unsigned short Hash::searchItem(string key)
{
    unsigned short result = 0;
    measureExecutionTime([&]() {
        // get the hash index of key
        unsigned short index;
        if (mode) {
            index = hashFunctionMultiplication(key);
        }
        else {
            index = hashFunctionDivision(key);
        }

        // find the key in (index)th list
        list<pair<string, unsigned short>>::iterator i;
        for (i = table[index].begin();
            i != table[index].end(); i++) {
            if (i->first == key) {
                result = i->second;
                break;
            }
        }
        });
    return result;
}

unsigned short const Hash::hashFunctionDivision(string key) {
    unsigned short sum = 0;
    for (char c : key) {
        sum += c;
    }
    return (sum % BUCKET);
}

unsigned short const Hash::hashFunctionMultiplication(string key) {
    const double M = 0.6180339887; // golden ratio
    const double C = 0.5; // constant value
    double hashValue = 0;
    for (char c : key) {
        hashValue += C * c;
    }
    hashValue *= M;
    return static_cast<unsigned short>(BUCKET * (hashValue - static_cast<unsigned short>(hashValue)));
}

void Hash::setModeDivision() {
    measureExecutionTime([&]() {
        mode = false;
        });
}

void Hash::setModeMultiplication() {
    measureExecutionTime([&]() {
        mode = true;
        });
}

string Hash::displayHash() {
    string result;
    measureExecutionTime([&]() {
        for (unsigned short i = 0; i < BUCKET; i++) {
            result += to_string(i);
            for (auto x : table[i])
                result += " --> (" + x.first + ", " + to_string(x.second) + ")";
            result += "\n";
        }
        });
    return result;
}

template<typename Func>
void Hash::measureExecutionTime(Func&& func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    exec_time = static_cast<unsigned int>(duration.count());
}

unsigned int Hash::getExecutionTime() {
    return exec_time;
}

string Hash::dehashItem(unsigned short bucket) {
    string result;
    measureExecutionTime([&]() {
        if (bucket >= BUCKET) {
            result = "";
        }
        else if (table[bucket].empty()) {
            result = "";
        }
        else {
            for (auto pair : table[bucket]) {
                result += pair.first + " " + to_string(pair.second) + "\n";
            }
        }
        });
    return result;


}

Hash::~Hash()
{
    delete[] table;
};