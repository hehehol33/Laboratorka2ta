#pragma once

#include <iostream>
#include <string>
#include <iostream>
#include <chrono>

class QueueArr {
private:
    unsigned short queue_size;
    std::string* String_queue = nullptr;
    unsigned int exec_time;

    template<typename Func>
    void measureExecutionTime(Func&& func);

public:
    QueueArr();
    void Enqueue(const std::string& entity);
    std::string Dequeue();
    void ShowQueue();
    unsigned int ExecTime() const;
    std::string* GetQueue();
    unsigned short getSize();
    ~QueueArr();
};

struct Node {
    std::string data;
    Node* next;
    Node(std::string value) : data(value), next(nullptr) {}
};

class NodeQueue {
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    unsigned short size = 0;
    unsigned int exec_time;

    template<typename Func>
    void measureExecutionTime(Func&& func);

public:
    void Enqueue(std::string element);
    std::string Dequeue();
    std::string* GetQueue();
    void ShowQueue();
    unsigned short getSize() const;
    unsigned int ExecTime() const;
    ~NodeQueue();
};