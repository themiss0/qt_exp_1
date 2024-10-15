#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <iostream>

void MainWindow::on_b_backspace_clicked()
{
    bool check;
    double num = now.toDouble(&check);
    if (!check)
    {
        ui->statusbar->showMessage("Error on button_backspace");
        return;
    }

    if (now.length() == 1)
    {

        if (num == 0)
        {
            return;
        }
        else
        {
            now = "0";
            refresh_display();
            return;
        }
    }

    if (now.length() == 2 && num < 0)
    {
        now = "0";
        refresh_display();
        return;
    }

    now.removeLast();
    if (now.length() == 2 && num == 0)
    {
        now = "0";
        refresh_display();
        return;
    }
    refresh_display();
    return;
}

void MainWindow::on_b_ce_clicked()
{
    if (ifOutput)
    {
        on_b_c_clicked();
        return;
    }
    now = "0";
    refresh_display();
    return;
}

void MainWindow::on_b_c_clicked()
{
    now = "0";
    operation = 'o';
    last = "0";
    result = "";
    ifOutput = false;
    refresh_display();
    return;
}

void MainWindow::on_b_equal_clicked()
{

    if (operation == 'o')
    {
        return;
    }

    bool check;
    double result = calculate(operation, &check);

    QString *temp = new QString();
    temp->setNum(result);
    statusMessage.append(*temp);
    delete temp;

    now.setNum(result);

    refresh_display();
    return;
}
