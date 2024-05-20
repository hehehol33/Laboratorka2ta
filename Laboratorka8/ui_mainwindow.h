/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mygraphicsview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    MyGraphicsView *treeView;
    QLabel *label_1;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *insertBox;
    QPushButton *insertButton;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *eraseNBox;
    QPushButton *eraseNButton;
    QGroupBox *groupBox_3;
    QLineEdit *findBox;
    QPushButton *searchButton;
    QLabel *label;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1122, 752);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(0, 0, 189);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        treeView = new MyGraphicsView(centralwidget);
        treeView->setObjectName("treeView");
        label_1 = new QLabel(treeView);
        label_1->setObjectName("label_1");
        label_1->setGeometry(QRect(10, 660, 91, 51));

        horizontalLayout_2->addWidget(treeView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(comboBox);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setObjectName("verticalLayout_5");
        insertBox = new QLineEdit(groupBox);
        insertBox->setObjectName("insertBox");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(insertBox->sizePolicy().hasHeightForWidth());
        insertBox->setSizePolicy(sizePolicy);
        insertBox->setMinimumSize(QSize(280, 0));

        verticalLayout_5->addWidget(insertBox);

        insertButton = new QPushButton(groupBox);
        insertButton->setObjectName("insertButton");

        verticalLayout_5->addWidget(insertButton);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        eraseNBox = new QLineEdit(groupBox_2);
        eraseNBox->setObjectName("eraseNBox");
        sizePolicy.setHeightForWidth(eraseNBox->sizePolicy().hasHeightForWidth());
        eraseNBox->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(eraseNBox);

        eraseNButton = new QPushButton(groupBox_2);
        eraseNButton->setObjectName("eraseNButton");

        verticalLayout_4->addWidget(eraseNButton);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        findBox = new QLineEdit(groupBox_3);
        findBox->setObjectName("findBox");
        findBox->setGeometry(QRect(10, 50, 281, 31));
        sizePolicy.setHeightForWidth(findBox->sizePolicy().hasHeightForWidth());
        findBox->setSizePolicy(sizePolicy);
        searchButton = new QPushButton(groupBox_3);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(10, 100, 281, 24));
        label = new QLabel(groupBox_3);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 140, 261, 51));

        verticalLayout->addWidget(groupBox_3);


        horizontalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1122, 21));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "TreeManager", nullptr));
        label_1->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\220\320\222\320\233-\320\264\320\265\321\200\320\265\320\262\320\276", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\247\320\265\321\200\320\262\320\276\320\275\320\276-\321\207\320\276\321\200\320\275\320\265 \320\264\320\265\321\200\320\265\320\262\320\276", nullptr));

        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\264\320\260\321\202\320\270 \320\277\321\200\320\270\320\273\320\260\320\264 \320\267 \321\203\320\275\321\226\320\272\320\260\320\273\321\214\320\275\320\276\321\216 \320\277\320\276\321\202\321\203\320\266\320\275\321\226\321\201\321\202\321\216", nullptr));
        insertButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\264\320\260\321\202\320\270 \320\277\321\200\320\270\320\273\320\260\320\264", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\264\320\260\320\273\320\265\320\275\320\275\321\217 \320\267\320\273\320\260\320\274\320\260\320\275\320\276\320\263\320\276 \320\277\321\200\320\270\320\273\320\260\320\264\321\203", nullptr));
        eraseNButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\264\320\260\320\273\320\270\321\202\320\270 \320\277\321\200\320\270\320\273\320\260\320\264", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\320\227\320\275\320\260\320\271\321\202\320\270 \320\277\321\200\320\270\320\273\320\260\320\264 ,\321\217\320\272\320\270\320\271 \320\262\321\226\320\264\320\277\320\276\320\262\321\226\320\264\320\260\321\224 \320\267\320\260\320\264\320\260\320\275\321\226\320\271 \320\277\320\276\321\202\321\203\320\266\320\275\320\276\321\201\321\202\321\226 \321\200\320\276\320\261\320\276\321\202\320\260", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\275\320\260\320\271\321\202\320\270 \320\277\321\200\320\270\320\273\320\260\320\264", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
