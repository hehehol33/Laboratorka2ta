#pragma once

#include "binarysearchtree.h"
#include <stack>


class avl : public BinarySearchTree
{
public:
   
    avl() {
        root = nullptr;
    }

    // Деструктор класу avl, видаляє всі вузли дерева
    ~avl() {
        if (root == nullptr) return;
        std::stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            auto t = st.top();
            st.pop();
            if (t->getL() != nullptr) st.push(t->getL());
            if (t->getR() != nullptr) st.push(t->getR());
            delete t;
        }
    }

    // Вставка нового елемента в дерево
    void insert(long long val) {
        root = _insert(root, val);
    }

    // Видалення елемента з дерева
    void erase(long long val) {
        root = _erase(root, val);
    }

    // Пошук елемента в дереві
    Node* find(long long val, QString& path) {
        return _find(root, val, path);
    }

    // Отримання кореневого вузла дерева
    Node* getRoot() {
        return root;
    }

    // Оновлення висоти вузлів дерева
    void updateHeight(Node* head) {
        if (head == nullptr) return;
        updateHeight(head->left);
        updateHeight(head->right);
        head->height = 1 + std::max(height(head->left), height(head->right));
    }

private:
    Node* root; // Кореневий вузол дерева

    // Отримання висоти вузла
    int height(Node* head) {
        if (head == nullptr) return 0;
        return head->height;
    }

    // Поворот вузла вправо
    Node* rightRotation(Node* head) {
        Node* newhead = head->left;
        head->left = newhead->right;
        newhead->right = head;
        head->height = 1 + std::max(height(head->left), height(head->right));
        newhead->height = 1 + std::max(height(newhead->left), height(newhead->right));
        return newhead;
    }

    // Поворот вузла вліво
    Node* leftRotation(Node* head) {
        Node* newhead = head->right;
        head->right = newhead->left;
        newhead->left = head;
        head->height = 1 + std::max(height(head->left), height(head->right));
        newhead->height = 1 + std::max(height(newhead->left), height(newhead->right));
        return newhead;
    }

    // Вставка нового вузла
    Node* _insert(Node* head, long long x) {
        if (head == nullptr) {
            return new Node(x);
        }
        if (x < head->getKey()) head->left = _insert(head->left, x);
        else if (x > head->getKey()) head->right = _insert(head->right, x);

        head->height = 1 + std::max(height(head->left), height(head->right));
        int bal = height(head->left) - height(head->right);

        // Балансування дерева
        if (bal > 1) {
            if (x < head->left->getKey()) {
                return rightRotation(head);
            }
            else {
                head->left = leftRotation(head->left);
                return rightRotation(head);
            }
        }
        else if (bal < -1) {
            if (x > head->right->getKey()) {
                return leftRotation(head);
            }
            else {
                head->right = rightRotation(head->right);
                return leftRotation(head);
            }
        }
        return head;
    }

    // Видалення вузла
    Node* _erase(Node* head, long long x) {
        if (head == nullptr) return nullptr;

        if (x < head->key) {
            head->left = _erase(head->left, x);
        }
        else if (x > head->key) {
            head->right = _erase(head->right, x);
        }
        else {
            Node* r = head->right;
            if (head->right == nullptr) {
                Node* l = head->left;
                delete(head);
                head = l;
            }
            else if (head->left == nullptr) {
                delete(head);
                head = r;
            }
            else {
                while (r->left != nullptr) r = r->left;
                head->key = r->key;
                head->right = _erase(head->right, r->key);
            }
        }

        if (head == nullptr) return head;

        head->height = 1 + std::max(height(head->left), height(head->right));
        int bal = height(head->left) - height(head->right);

        // Балансування дерева
        if (bal > 1) {
            if (height(head->left) >= height(head->right)) {
                return rightRotation(head);
            }
            else {
                head->left = leftRotation(head->left);
                return rightRotation(head);
            }
        }
        else if (bal < -1) {
            if (height(head->right) >= height(head->left)) {
                return leftRotation(head);
            }
            else {
                head->right = rightRotation(head->right);
                return leftRotation(head);
            }
        }
        return head;
    }

    // Пошук вузла за значенням
    Node* _find(Node* head, long long x, QString& path) {
        if (head == nullptr) return nullptr;

        long long k = head->key;
        path += QString::number(k) + " "; // Додаємо поточний ключ до шляху

        if (k > x) {
            path += "(Left) -> "; // Додаємо напрямок пошуку (ліворуч)
            return _find(head->left, x, path); // Переміщуємося вліво і додаємо ключ до шляху
        }
        if (k < x) {
            path += "(Right) -> "; // Додаємо напрямок пошуку (праворуч)
            return _find(head->right, x, path); // Переміщуємося вправо і додаємо ключ до шляху
        }

        // Якщо знайдено потрібний елемент, додаємо його ключ і повертаємо його
        path += "|Found (" + QString::number(k) + ")";
        return head;
    }
};
