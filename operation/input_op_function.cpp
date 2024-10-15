#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <iostream>

void MainWindow::on_num_clicked()
{

    if (now.toDouble() == 0 && !now.contains('.'))
    {
        QString temp = qobject_cast<QPushButton *>(sender())->text();
        if (temp == "0")
        {
            return;
        }
        else
        {
            now = temp;
        }
    }
    else
    {
        now += qobject_cast<QPushButton *>(sender())->text();
    }
    refresh_display();
}

void MainWindow::on_b_point_clicked()
{
    if (now.contains('.'))
    {
        return;
    }

    now.append('.');
    refresh_display();
    return;
}

void MainWindow::on_b_p_or_n_clicked()
{
    bool check;
    double num = now.toDouble(&check);
    if (!check)
    {
        ui->statusbar->showMessage("Error on button p_or_n: " + now);
        return;
    }
    if (num == 0 && !now.contains('.'))
    {
        return;
    }

    if (num < 0 || now.at(0) == '-')
    {
        now.removeFirst();
    }
    else
    {
        now = "-" + now;
    }
    refresh_display();
}