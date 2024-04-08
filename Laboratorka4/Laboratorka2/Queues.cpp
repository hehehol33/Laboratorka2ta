#include "TaQueues.h"

// Queue methods implementation

template<typename Func>
void ArrQueue::measureExecutionTime(Func&& func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    exec_time = static_cast<unsigned int>(duration.count());
}

ArrQueue::ArrQueue() {
    measureExecutionTime([this] {
        queue_size = 0;
        Shrt_queue = new unsigned short[queue_size];
        });
}

void ArrQueue::Enqueue(const unsigned short& entity) {
    measureExecutionTime([this, &entity] {
        unsigned short* Temp_queue = new unsigned short[queue_size + 1];
        for (unsigned short i = 0; i < queue_size; i++) {
            Temp_queue[i] = Shrt_queue[i];
        }
        Temp_queue[queue_size] = entity;
        delete[] Shrt_queue;
        Shrt_queue = Temp_queue;
        queue_size++;
        });
}

unsigned short ArrQueue::Dequeue() {
    unsigned short value;
    measureExecutionTime([this, &value] {
        if (queue_size > 0) {
            unsigned short temp_size = queue_size;
            unsigned short* Temp_queue = new unsigned short[temp_size];
            for (unsigned short i = 1; i < queue_size; i++) {
                Temp_queue[i - 1] = Shrt_queue[i];
            }
            value = Shrt_queue[0];
            delete[] Shrt_queue;
            Shrt_queue = Temp_queue;
            queue_size--;
        }
        });
    return value;
}

void ArrQueue::ShowQueue() {
    measureExecutionTime([this] {
        for (unsigned short i = 0; i < queue_size; i++) {
            std::cout << Shrt_queue[i] << "\n";
        }
        std::cout << "\n";
        });
}

unsigned int ArrQueue::ExecTime() const {
    return exec_time;
}

unsigned short* ArrQueue::GetQueue() {
    unsigned short* copyQueue = nullptr;
    measureExecutionTime([this, &copyQueue] {
        copyQueue = new unsigned short[queue_size];
        for (unsigned short i = 0; i < queue_size; ++i) {
            copyQueue[i] = Shrt_queue[i];
        }
        });
    return copyQueue;
}

unsigned short ArrQueue::getSize() {
    return queue_size;
}

ArrQueue::~ArrQueue() {
    delete[] Shrt_queue;
}

// NodeQueue methods implementation

template<typename Func>
void NodeQueue::measureExecutionTime(Func&& func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    exec_time = static_cast<unsigned int>(duration.count());
}

void NodeQueue::Enqueue(unsigned short element) {
    measureExecutionTime([this, &element] {
        Node* newNode = new Node(element);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
        });
}

unsigned short NodeQueue::Dequeue() {
    unsigned short value;
    measureExecutionTime([this, &value] {
        if (head == nullptr) {
            throw std::runtime_error("Queue is empty");
        }
        value = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        });
    return value;
}

unsigned short* NodeQueue::GetQueue() {
    unsigned short* elementsArray = nullptr;
    measureExecutionTime([this, &elementsArray] {
        elementsArray = new unsigned short[size];
        Node* current = head;
        unsigned short index = 0;
        while (current != nullptr) {
            elementsArray[index++] = current->data;
            current = current->next;
        }
        });
    return elementsArray;
}

void NodeQueue::ShowQueue() {
    measureExecutionTime([this] {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
        });
}

unsigned short NodeQueue::getSize() const {
    return size;
}

unsigned int NodeQueue::ExecTime() const {
    return exec_time;
}

NodeQueue::~NodeQueue() {
    while (head != nullptr) {
        Dequeue();
    }
}