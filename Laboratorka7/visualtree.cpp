#include "visualtree.h"
#include "ui_visualtree.h"
#include <iostream>
#include <QString>
#include "tree.h"
#include <QPainter>
#include <QPoint>
#include <string>
#include <sstream>


int Tree::Node::left_nodes = 0;
int Tree::Node::right_nodes = 0;

VisualTree::VisualTree(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::VisualTree)
{
    ui->setupUi(this);
}

VisualTree::~VisualTree()
{
    delete _node;
    delete ui;
}

void VisualTree::on_insert_button_clicked()
{
    QString raw_data = ui->Input_text->text();
    ui->Input_text->setText("");

    if (raw_data.contains(",")) {
        _node->ResetLastLabel();
        QStringList split_data = raw_data.split(",");

        for (const auto& a : split_data) {
            Tree::Data _data;
            _data.val = a.toInt();
            _node->Insert(_data);

          
          
        }
    }
    else {
        Tree::Data _data;
        _data.val = raw_data.toInt();
        if (!(_node->Contain(raw_data.toInt()))) {
            _node->ResetLastLabel();
            _node->Insert(_data);

         
        }
    }
    ui->label_time->setText(QString::number(_node->exec_time) + " ns");
    DrawTree = true;
    update();
}

void VisualTree::on_Root_set_clicked()
{
    int root = ui->Root_inp->text().toInt();

    Tree::Data r_data;
    r_data.val = root;

    _node = new Tree::Node(r_data);

    ui->Root_inp->setEnabled(false);
    ui->Root_set->setEnabled(false);
}

void VisualTree::on_pushButton_clicked()
{
}
void VisualTree::on_search_button_clicked() {
    QString raw_search = ui->search_input->text();
    int search_val = raw_search.toInt();

    ui->search_input->setText("");

    _node->ResetSearchResultFlag();

    std::ostringstream path_stream;
    bool found = false;
    auto start = std::chrono::high_resolution_clock::now();
    Tree::Node* current = _node;
    while (current != nullptr) {
        int current_val = current->_data.val;

        if (search_val < current_val) {
            path_stream << current_val << " Left -> ";
            current = current->_left;
        }
        else if (search_val > current_val) {
            path_stream << current_val << " Right -> ";
            current = current->_right;
        }
        else {
            path_stream << " Found (" << current_val << ")";
            found = true;
            current->_data.is_search_result = true;
            break;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    if (!found) {
        ui->Search_path->setText("Element not found in the tree.");
    }
    else {
        ui->Search_path->setText(QString::fromStdString(path_stream.str()));
    }
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    unsigned int exec_time = static_cast<unsigned int>(duration.count());
    ui->label_time->setText(QString::number(exec_time) + " ns");
    DrawTree = true;
    update();

}


void VisualTree::paintEvent(QPaintEvent* event) {
    QPainter painter(this);

    // Встановлення кольору фону
    painter.fillRect(rect(), Qt:: darkBlue); // Білий фон, але можна обрати інший колір

    if (DrawTree) {
        painter.setPen(QPen(Qt::black, 2));

        std::vector<Tree::Data> nodes_data = _node->SetPositionOfNodesForVisualization();

        // Лінії між вузлами
        QPoint line_pos;
        line_pos.setX(_node->start_pos.x());
        line_pos.setY(_node->start_pos.y());
        std::vector<QPoint> nodes_lines = _node->GetVectorOfLinesBetwenNodes();

        for (const auto& point : nodes_lines) {
            painter.drawLine(line_pos.x(), line_pos.y(), point.x(), point.y());
            line_pos = point;
        }

        const int radius = _node->DrawingSize / 2;

        // Вузли дерева
        for (const auto& node : nodes_data) {
            if (node.is_search_result) {
                painter.setBrush(QBrush(Qt::blue)); // Якщо це результат пошуку
            }
            else if (node.new_node) {
                painter.setBrush(QBrush(Qt::red)); // Якщо це новий вузол
            }
            else {
                painter.setBrush(QBrush(Qt::green)); // За замовчуванням
            }

            painter.drawEllipse(node.posX - radius, node.posY - radius, _node->DrawingSize, _node->DrawingSize);
            painter.drawText(QRectF(QPointF(QPoint(node.posX - radius, node.posY - radius)), QSizeF(34, 31)), QString::number(node.val), QTextOption(Qt::AlignCenter));
        }
    }

}