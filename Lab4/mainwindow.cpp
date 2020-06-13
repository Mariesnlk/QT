#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QListWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QListWidget *list1 = ui->listWidget1;
    QListWidget *list2 = ui->listWidget2;

    list1->setDragDropMode(QAbstractItemView::DragDrop);
    list1->setDefaultDropAction(Qt::MoveAction);
    list2->setDragDropMode(QAbstractItemView::DragDrop);
    list2->setDefaultDropAction(Qt::MoveAction);

    list1->addItem("Mariia");
    list1->addItem("Yulia");
    list1->addItem("Anna");
    list1->addItem("Emma");

    list2->addItem("Oleg");
    list2->addItem("Andriy");
    list2->addItem("Maks");
    list2->addItem("Sasha");

}

MainWindow::~MainWindow()
{
    delete ui;
}
