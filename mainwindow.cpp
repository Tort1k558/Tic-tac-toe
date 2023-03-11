#include "mainwindow.h"
#include "tictactoe.h"
#include "./ui_mainwindow.h"
#include<iostream>
#include <QHBoxLayout>
#include <QFile>
#include <QTextStream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    TicTacToeGame *game = new TicTacToeGame(this);
    game->setObjectName("TicTacToeGame");
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(game);
    this->centralWidget()->setLayout(layout);
    this->centralWidget()->setStyleSheet("QWidget#centralwidget {border-image:url(\"assets/field.png\");background-position: center; }");
}

MainWindow::~MainWindow()
{
    delete ui;
}

