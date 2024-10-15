#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->b_0, SIGNAL(clicked()), this, SLOT(on_num_clicked()));
    connect(ui->b_1, SIGNAL(clicked()), this, SLOT(on_num_clicked()));
    connect(ui->b_2, SIGNAL(clicked()), this, SLOT(on_num_clicked()));
    connect(ui->b_3, SIGNAL(clicked()), this, SLOT(on_num_clicked()));
    connect(ui->b_4, SIGNAL(clicked()), this, SLOT(on_num_clicked()));
    connect(ui->b_5, SIGNAL(clicked()), this, SLOT(on_num_clicked()));
    connect(ui->b_6, SIGNAL(clicked()), this, SLOT(on_num_clicked()));
    connect(ui->b_7, SIGNAL(clicked()), this, SLOT(on_num_clicked()));
    connect(ui->b_8, SIGNAL(clicked()), this, SLOT(on_num_clicked()));
    connect(ui->b_9, SIGNAL(clicked()), this, SLOT(on_num_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
