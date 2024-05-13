#include "tree.h"
#include <iostream>
#include <vector>
#include <QPoint>

namespace Tree {

    
    Node::Node(Data NewData) {
        _data = NewData;
    }

    Node::~Node() {
        delete _left;
        delete _right;
    }
    template<typename Func> // Шаблон для измерения времени выполнения функции 
    void Node::measureExecutionTime(Func&& func) { // Принимает функцию, которую надо выполнить
        auto start = std::chrono::high_resolution_clock::now(); // Записывает время начала выполнения
        func(); // Выполняет функцию
        auto end = std::chrono::high_resolution_clock::now(); // записывает время окончания выполнения
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start); // Считает разницу 
        exec_time = static_cast<unsigned int>(duration.count()); // Записывает время выполнения в переменную
    }


    void Node::Insert(Data NewData) {
        // Використовуйте measureExecutionTime для вимірювання часу виконання коду
        measureExecutionTime([this, &NewData]() {
            if (NewData.val < _data.val) {
                if (_left == nullptr) {
                    left_nodes++;
                    _left = new Node(NewData);
                    _left->_data.new_node = true;
                }
                else {
                    _left->Insert(NewData);
                }
            }
            else if (NewData.val > _data.val) {
                if (_right == nullptr) {
                    right_nodes++;
                    _right = new Node(NewData);
                    _right->_data.new_node = true;
                }
                else {
                    _right->Insert(NewData);
                }
            }
            });
    }
    Node* Node::Search(int key) {
        Node* result = nullptr; // Змінна для збереження результату пошуку

        // Вимірювання часу виконання пошуку
        measureExecutionTime([&]() {
            Node* current = this; // Починаємо з поточного вузла (кореневий вузол)
            while (current != nullptr) { // Продовжуємо поки не дійдемо до кінця
                if (key == current->_data.val) { // Знайдено відповідний вузол
                    result = current;
                    break; // Виходимо з циклу
                }
                else if (key < current->_data.val) { // Йдемо вліво
                    current = current->_left;
                }
                else { // Йдемо вправо
                    current = current->_right;
                }
            }
            });

        return result; // Повертаємо результат
    }


    Node* Node::search(int key, Node* node) {
       
        if (node == nullptr) {
            return nullptr;
        }

        if (node->_data.val == key) {
            return node;
        }

        if (key < node->_data.val) {
            return search(key, node->_left);
        }
        else {
            return search(key, node->_right);
        }
    }

    void Node::ResetLastLabel() {
        if (_left != nullptr) {
            _left->_data.new_node = false;
            _left->ResetLastLabel();
        }

        if (_right != nullptr) {
            _right->_data.new_node = false;
            _right->ResetLastLabel();
        }
    }

    bool Node::Contain(int number) {
        if (number < _data.val) {
            if (_left == nullptr) {
                return false;
            }
            else {
                _left->Contain(number);
            }
        }
        else if (number > _data.val)
        {
            if (_right == nullptr) {
                return false;
            }
            else {
                _right->Contain(number);
            }
        }
        else {
            return true;
        }
    }





    void Node::GetSortedVector(std::vector<int>& a)
    {
        if (_left != nullptr) {
            _left->GetSortedVector(a);
        }
        a.push_back(_data.val);

        if (_right != nullptr) {
            _right->GetSortedVector(a);
        }
    }

    std::vector<Data> Node::SetPositionOfNodesForVisualization() {
        int level{ 0 }, pos{ 1 };
        this->SetLevel(level);
        this->SetPos(pos);
        this->SetDataForDrawing(*this);
        std::vector<Data> vec;
        this->ReturnDataVector(vec);

        return vec;

    }


    std::vector<QPoint> Node::GetVectorOfLinesBetwenNodes() {
        std::vector<QPoint> vec;
        this->LoopForLinesConnection(vec);
        return vec;
    }

    void Node::LoopForLinesConnection(std::vector<QPoint>& vec) {

        if (_left != nullptr) {
            QPoint point(_data.posX, _data.posY);
            vec.push_back(point);
            _left->LoopForLinesConnection(vec);
        }

        if (_right != nullptr) {
            QPoint point(_data.posX, _data.posY);
            vec.push_back(point);
            _right->LoopForLinesConnection(vec);
        }

        QPoint point(_data.posX, _data.posY);
        vec.push_back(point);
    }



    void Node::ReturnDataVector(std::vector<Data>& vector) {
        if (_left != nullptr) {
            _left->ReturnDataVector(vector);
        }

        vector.push_back(_data);

        if (_right != nullptr) {
            _right->ReturnDataVector(vector);
        }
    }
    void Node::ResetSearchResultFlag() {
        _data.is_search_result = false;
        if (_left) {
            _left->ResetSearchResultFlag();
        }
        if (_right) {
            _right->ResetSearchResultFlag();
        }
    }

    void Node::SetDataForDrawing(Node& root) {
        if (_left != nullptr) {
            _left->SetDataForDrawing(root);
        }

        _data.posY = (_data.level * root.DrawingSize) + root.start_pos.y();
        if (_data.pos < root._data.pos) {
            _data.posX = root.start_pos.x() - ((root._data.pos - _data.pos) * root.DrawingSize);
        }
        else if (_data.pos > root._data.pos) {
            _data.posX = root.start_pos.x() + ((_data.pos - root._data.pos) * root.DrawingSize);
        }
        else {
            _data.posX = root.start_pos.x();
        }

        if (_right != nullptr) {
            _right->SetDataForDrawing(root);
        }
    }

    void Node::SetPos(int& pos) {
        if (_left != nullptr) {
            _left->SetPos(pos);
        }
        _data.pos = pos;
        pos++;
        if (_right != nullptr) {
            _right->SetPos(pos);
        }
    }

    void Node::SetLevel(int& level) {
        _data.level = level;
        level++;
        if (_left != nullptr) {
            _left->SetLevel(level);
        }
        if (_right != nullptr) {
            _right->SetLevel(level);
        }
        level--;
    }
}
