#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <iostream>

// 减
void MainWindow::on_b_sub_clicked()
{
    QString op = "-";
    operate(op[0]);
}
// 乘
void MainWindow::on_b_multi_clicked()
{

    QString op = "*";
    operate(op[0]);
}
// 除
void MainWindow::on_b_devide_clicked()
{

    QString op = "/";
    operate(op[0]);
}
// 加
void MainWindow::on_b_add_clicked()
{
    QString op = "+";
    operate(op[0]);
}
