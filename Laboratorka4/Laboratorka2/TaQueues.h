#pragma once

#include <iostream>
#include <iostream>
#include <chrono>

class ArrQueue {
private:
    unsigned short queue_size;
    unsigned short* Shrt_queue = nullptr;
    unsigned int exec_time;

    template<typename Func>
    void measureExecutionTime(Func&& func);

public:
    ArrQueue();
    void Enqueue(const unsigned short& entity);
    unsigned short Dequeue();
    void ShowQueue();
    unsigned int ExecTime() const;
    unsigned short* GetQueue();
    unsigned short getSize();
    ~ArrQueue();
};

struct Node {
    unsigned short data;
    Node* next;
    Node(unsigned short value) : data(value), next(nullptr) {}
};

class NodeQueue {
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    unsigned int exec_time;
    unsigned short size;
    template<typename Func>
    void measureExecutionTime(Func&& func);

public:
    void Enqueue(unsigned short element);
    unsigned short Dequeue();
    unsigned short* GetQueue();
    void ShowQueue();
    unsigned short getSize() const;
    unsigned int ExecTime() const;
    ~NodeQueue();
};