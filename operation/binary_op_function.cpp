#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <iostream>

// 减
void MainWindow::on_b_sub_clicked()
{
}
// 乘
void MainWindow::on_b_multi_clicked()
{
}
// 除
void MainWindow::on_b_devide_clicked()
{
}
// 加
void MainWindow::on_b_add_clicked()
{

    bool check;
    double num = now.toDouble();

    if (!operation.isEmpty())
    {
        if (restart_input)
        {

            restart_input = false;
            

            operation = "+";
            return;
        }
        n = calculate(operation[0], &check);
    }

    operation = "+";
    now = "0";

    refresh_display();
}
