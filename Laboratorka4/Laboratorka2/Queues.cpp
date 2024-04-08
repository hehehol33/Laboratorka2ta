#include "TaQueues.h"

// Queue methods implementation

template<typename Func>
void QueueArr::measureExecutionTime(Func&& func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    exec_time = static_cast<unsigned int>(duration.count());
}

QueueArr::QueueArr() {
    measureExecutionTime([this] {
        queue_size = 0;
        String_queue = new std::string[queue_size];
        });
}

void QueueArr::Enqueue(const std::string& entity) {
    measureExecutionTime([this, &entity] {
        std::string* Temp_queue = new std::string[queue_size + 1];
        for (unsigned short i = 0; i < queue_size; i++) {
            Temp_queue[i] = String_queue[i];
        }
        Temp_queue[queue_size] = entity;
        delete[] String_queue;
        String_queue = Temp_queue;
        queue_size++;
        });
}

std::string QueueArr::Dequeue() {
    std::string value;
    measureExecutionTime([this, &value] {
        if (queue_size > 0) {
            unsigned short temp_size = queue_size;
            std::string* Temp_queue = new std::string[temp_size];
            for (unsigned short i = 1; i < queue_size; i++) {
                Temp_queue[i - 1] = String_queue[i];
            }
            value = String_queue[0];
            delete[] String_queue;
            String_queue = Temp_queue;
            queue_size--;
        }
        });
    return value;
}

void QueueArr::ShowQueue() {
    measureExecutionTime([this] {
        for (unsigned short i = 0; i < queue_size; i++) {
            std::cout << String_queue[i] << " ";
        }
        std::cout << "\n";
        });
}

unsigned int QueueArr::ExecTime() const {
    return exec_time;
}

std::string* QueueArr::GetQueue() {
    std::string* copyQueue = nullptr;
    measureExecutionTime([this, &copyQueue] {
        copyQueue = new std::string[queue_size];
        for (unsigned short i = 0; i < queue_size; ++i) {
            copyQueue[i] = String_queue[i];
        }
        });
    return copyQueue;
}

unsigned short QueueArr::getSize() {
    return queue_size;
}

QueueArr::~QueueArr() {
    delete[] String_queue;
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

void NodeQueue::Enqueue(std::string element) {
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

std::string NodeQueue::Dequeue() {
    std::string value;
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

std::string* NodeQueue::GetQueue() {
    std::string* elementsArray = nullptr;
    measureExecutionTime([this, &elementsArray] {
        elementsArray = new std::string[size];
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