/********************************************************************************
** Form generated from reading UI file 'visualtree.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISUALTREE_H
#define UI_VISUALTREE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VisualTree
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLineEdit *Input_text;
    QPushButton *insert_button;
    QLabel *label_2;
    QLineEdit *Root_inp;
    QPushButton *Root_set;
    QLabel *right_branch;
    QLabel *label_time;
    QLineEdit *search_input;
    QLabel *label_7;
    QPushButton *search_button;
    QTextBrowser *Search_path;
    QLabel *label_3;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VisualTree)
    {
        if (VisualTree->objectName().isEmpty())
            VisualTree->setObjectName("VisualTree");
        VisualTree->resize(753, 449);
        VisualTree->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(VisualTree);
        centralWidget->setObjectName("centralWidget");
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 60, 81, 41));
        label->setStyleSheet(QString::fromUtf8("color: rgb(216, 253, 255);"));
        Input_text = new QLineEdit(centralWidget);
        Input_text->setObjectName("Input_text");
        Input_text->setGeometry(QRect(80, 70, 191, 25));
        Input_text->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 221, 255);"));
        insert_button = new QPushButton(centralWidget);
        insert_button->setObjectName("insert_button");
        insert_button->setGeometry(QRect(290, 70, 89, 25));
        insert_button->setStyleSheet(QString::fromUtf8("font: 10pt \"Times New Roman\";\n"
"border: 1px solid white;\n"
"color: rgb(216, 253, 255);"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 20, 81, 21));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(216, 253, 255);"));
        Root_inp = new QLineEdit(centralWidget);
        Root_inp->setObjectName("Root_inp");
        Root_inp->setGeometry(QRect(80, 20, 191, 25));
        Root_inp->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 221, 255);"));
        Root_set = new QPushButton(centralWidget);
        Root_set->setObjectName("Root_set");
        Root_set->setGeometry(QRect(290, 20, 89, 25));
        Root_set->setStyleSheet(QString::fromUtf8("font: 10pt \"Times New Roman\";\n"
"border: 1px solid white;\n"
"color: rgb(216, 253, 255);"));
        right_branch = new QLabel(centralWidget);
        right_branch->setObjectName("right_branch");
        right_branch->setGeometry(QRect(680, 60, 67, 17));
        label_time = new QLabel(centralWidget);
        label_time->setObjectName("label_time");
        label_time->setGeometry(QRect(110, 120, 81, 21));
        label_time->setStyleSheet(QString::fromUtf8("color: rgb(216, 253, 255);"));
        search_input = new QLineEdit(centralWidget);
        search_input->setObjectName("search_input");
        search_input->setGeometry(QRect(470, 20, 113, 25));
        search_input->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 221, 255);"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(390, 10, 71, 41));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(216, 253, 255);"));
        search_button = new QPushButton(centralWidget);
        search_button->setObjectName("search_button");
        search_button->setGeometry(QRect(600, 20, 89, 25));
        search_button->setStyleSheet(QString::fromUtf8("font: 10pt \"Times New Roman\";\n"
"border: 1px solid white;\n"
"color: rgb(216, 253, 255);"));
        Search_path = new QTextBrowser(centralWidget);
        Search_path->setObjectName("Search_path");
        Search_path->setGeometry(QRect(400, 60, 281, 41));
        Search_path->setStyleSheet(QString::fromUtf8("background-color: rgb(149, 149, 223);"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 110, 91, 41));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(216, 253, 255);"));
        VisualTree->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VisualTree);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 753, 21));
        VisualTree->setMenuBar(menuBar);
        statusBar = new QStatusBar(VisualTree);
        statusBar->setObjectName("statusBar");
        VisualTree->setStatusBar(statusBar);

        retranslateUi(VisualTree);

        QMetaObject::connectSlotsByName(VisualTree);
    } // setupUi

    void retranslateUi(QMainWindow *VisualTree)
    {
        VisualTree->setWindowTitle(QCoreApplication::translate("VisualTree", "VisualTree", nullptr));
        label->setText(QCoreApplication::translate("VisualTree", "Input :", nullptr));
        insert_button->setText(QCoreApplication::translate("VisualTree", "Insert", nullptr));
        label_2->setText(QCoreApplication::translate("VisualTree", "Root :", nullptr));
        Root_set->setText(QCoreApplication::translate("VisualTree", "Set", nullptr));
        right_branch->setText(QString());
        label_time->setText(QString());
        label_7->setText(QCoreApplication::translate("VisualTree", "<html><head/><body><p>Search input:</p></body></html>", nullptr));
        search_button->setText(QCoreApplication::translate("VisualTree", "Search", nullptr));
        label_3->setText(QCoreApplication::translate("VisualTree", "Execution time:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VisualTree: public Ui_VisualTree {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALTREE_H
