#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <iostream>

void MainWindow::on_b_sub_clicked()
{
}

void MainWindow::on_b_multi_clicked()
{
}

void MainWindow::on_b_devide_clicked()
{
}

void MainWindow::on_b_add_clicked()
{

    bool check;
    double num = now.toDouble(&check);
    if (!check)
    {
        ui->statusbar->showMessage("Error on button_add");
        return;
    }

    if (num != 0 && operation != 'o')
    {
        double re = calculate(operation, &check);
        last.setNum(re);
    }

    operation = '+';
    last = now;
    now = "0";

    ui->statusbar->showMessage(last + operation);
    refresh_display();
}


void MainWindow::on_b_persent_clicked()
{
    bool check;
    double num = now.toDouble(&check);
    if (!check)
    {
        ui->statusbar->showMessage("Error on button_persent");
        return;
    }

    now.setNum(num / 100);
    refresh_display();
    return;
}
