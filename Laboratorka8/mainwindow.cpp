#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWheelEvent>
#include <QFontDatabase>
#include <chrono>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFontDatabase::addApplicationFont("Consolas.ttf");

    scene = new QGraphicsScene();
    scene->setStickyFocus(true);

    t = new avl();
    drawTree(t);
    tree_type = TreeType::AVL;
    n = 0;
    updateInfo();

    ui->treeView->setScene(scene);
    ui->treeView->setTransformationAnchor(QGraphicsView::NoAnchor);
    ui->treeView->setRenderHint(QPainter::Antialiasing);
    ui->treeView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->treeView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->treeView->setAlignment(Qt::AlignCenter | Qt::AlignTop);
    ui->treeView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->treeView->setFocusPolicy(Qt::FocusPolicy::WheelFocus);
}

void MainWindow::updateInfo() {
    QString typeString = "";
    switch (tree_type) {
    case TreeType::None:
        typeString = "?";
        break;
    case TreeType::AVL:
        typeString = "АВЛ";
        break;
    case TreeType::RB:
        typeString = "Красно-черное";
        break;
   
    }
    
}

void MainWindow::eraseFunc(long long x) { // функия для удаления узла из дерева
    last_el = QString::number(x);
    if (tree_type == TreeType::AVL) {
        ((avl*)t)->erase(x);
    } else if (tree_type == TreeType::RB) {
        ((RBTree*)t)->erase(x);
    } 
    n--;
    els.erase(std::find(els.begin(), els.end(), x));
    drawTree(t);
}

void MainWindow::drawTree(BinarySearchTree* t) { // функия для рисования и обновления всего дерева по узлам
    auto start = std::chrono::high_resolution_clock::now();
    qDeleteAll(scene->items());
    delete scene;
    scene = new QGraphicsScene();
    ui->treeView->setScene(scene);
    if (t == nullptr || t->getRoot() == nullptr) {
        updateInfo();
        return;
    }
    if (selected != nullptr) {
        selected = nullptr;
    }

    if (tree_type == TreeType::AVL) {
        ((avl*)t)->getRoot()->updateSize();
    } else if (tree_type == TreeType::RB) {
        ((RBTree*)t)->getRoot()->updateSize();
    }
    updateInfo();
    if (tree_type == TreeType::AVL) {
        drawNode(((avl*)t)->getRoot(), 0, 0);
    } else if (tree_type == TreeType::RB) {
        drawNode(((RBTree*)t)->getRoot(), 0, 0);

    } 
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    unsigned int exec_time = static_cast<unsigned int>(duration.count());
    ui->label_1->setText(QString::number(exec_time) + " ns");
}

NodeItem* MainWindow::drawNode(Node* t, int x, int y)  { // функия для рисования сбалансированого дерева по узлам
    if (t == nullptr) return nullptr;
    NodeItem* node = new NodeItem(x, y, t->getKey(), sz, t->getColor(), this);
    scene->addItem(node);
    t->node = node;
    if (t->getL() != nullptr) {
        int lx = x - (t->getL()->getR() != nullptr ? t->getL()->getR()->size : 0) * sz - sz;
        scene->addItem(node->getEdge(drawNode(t->getL(), lx, y + sz * 2)));
    }
    if (t->getR() != nullptr) {
        int rx = x + (t->getR()->getL() != nullptr ? t->getR()->getL()->size : 0) * sz + sz;
        scene->addItem(node->getEdge(drawNode(t->getR(), rx, y + sz * 2)));
    }
    return node;
}
NodeItem* MainWindow::drawNode(RBNode* t, int x, int y) { // функия для рисования красно-черного дерева по узлам
    if (t == nullptr) return nullptr;
    NodeItem* node = new NodeItem(x, y, t->getKey(), sz, t->getColor(), this);
    scene->addItem(node);
    t->node = node;
    if (t->getL() != nullptr) {
        int lx = x - (t->getL()->getR() != nullptr ? t->getL()->getR()->size : 0) * sz - sz;
        scene->addItem(node->getEdge(drawNode(t->getL(), lx, y + sz * 2)));
    }
    if (t->getR() != nullptr) {
        int rx = x + (t->getR()->getL() != nullptr ? t->getR()->getL()->size : 0) * 80 + 80;
        scene->addItem(node->getEdge(drawNode(t->getR(), rx, y + sz * 2)));
    }
    return node;
}


MainWindow::~MainWindow() // деструктор
{
    delete ui;
}

void MainWindow::on_insertButton_clicked() // вставка нового узла по нажатию кнопки
{
    long long val = ui->insertBox->text().toLongLong();
    t->insert(val);
    n++;
    els.push_back(val);
    sort(els.begin(), els.end());
    last_el = QString::number(val);
    ui->insertBox->clear();
    drawTree(t);
}

void MainWindow::on_eraseNButton_clicked() // удаление введенного узла по нажатию кнопки
{
    if (els.size() == 0) return;

    // Get the value from eraseNBox and convert it to the appropriate type
    int val = ui->eraseNBox->text().toInt();

    // Find the element in the els list
    auto start = std::chrono::high_resolution_clock::now();
    auto it = std::find(els.begin(), els.end(), val);
    if (it != els.end()) {
        // Erase the element from the tree based on the tree type
        if (tree_type == TreeType::AVL) {
            ((avl*)t)->erase(val);
        }
        else if (tree_type == TreeType::RB) {
            ((RBTree*)t)->erase(val);
        }

        // Erase the element from the els list
        els.erase(it);
        n--;

        // Update last_el to the erased value
        last_el = QString::number(val);
    }
    auto end = std::chrono::high_resolution_clock::now();
    ui->eraseNBox->clear();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    unsigned int exec_time = static_cast<unsigned int>(duration.count());
    ui->label_1->setText(QString::number(exec_time) + " ns");
    // Redraw the tree
    drawTree(t);
}


void MainWindow::on_searchButton_clicked() // поиск узла по нажатию кнопки
{
    long long val = ui->findBox->text().toLongLong();
    QString path = ""; 
    if (selected != nullptr) {
        selected->node->_ellipse->setPen(QPen(selected->node->_color));
        selected->node->update();
    }
    auto start = std::chrono::high_resolution_clock::now();
    bool found = false; // Додаємо змінну для відстеження успішності пошуку
    if (tree_type == TreeType::AVL) {
        auto p = ((avl*)t)->find(val, path); // Викликаємо функцію пошуку з передачею шляху посиланням
        if (p != nullptr) {
            p->node->_ellipse->setPen(QPen(Qt::yellow, 3));
            p->node->update();
            selected = p;
            found = true;
        }
    }
    else if (tree_type == TreeType::RB) {
        auto p = ((RBTree*)t)->find(val, path); // Викликаємо функцію пошуку з передачею шляху посиланням
        if (p != nullptr) {
            p->node->_ellipse->setPen(QPen(Qt::yellow, 3));
            p->node->update();
            selected = p;
            found = true;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    if (found) {
        last_el = QString::number(val);
        ui->label->setText("Шлях: " + path); // Виводимо шлях на відповідний QLabel
    }
    else {
        ui->label->setText("Елемент не знайдений");
    }
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    unsigned int exec_time = static_cast<unsigned int>(duration.count());
    ui->label_1->setText(QString::number(exec_time) + " ns");
    ui->findBox->clear();
}


void MainWindow::on_comboBox_currentIndexChanged(int index) // вибір типу дерева
{
    switch(index) {
    case 0:
        t = new avl();
        drawTree(t);
        tree_type = TreeType::AVL;
        n = 0;
        updateInfo();
        break;
    case 1:
        t = new RBTree();
        drawTree(t);
        tree_type = TreeType::RB;
        n = 0;
        updateInfo();
        break;
    
    }
}

