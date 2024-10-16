#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <iostream>

// 平方根
void MainWindow::on_b_sqrt_clicked()
{
    if (step == 1)
    {
        step = 2;
    }
    if (step == 3)
    {
        step = 0;
    }

    if (now.toDouble() < 0)
    {
        statusMessage = "Error, invalid input";
        clear(true);
        return;
    }

    now.setNum(sqrt(now.toDouble()));

    refresh_display();
    return;
}
// 平方
void MainWindow::on_b_square_clicked()

{
    if (step == 1)
    {
        step = 2;
    }
    if (step == 3)
    {
        step = 0;
    }

    now.setNum(pow(now.toDouble(), 2));

    refresh_display();
    return;
}
// 倒数
void MainWindow::on_b_fraction_clicked()
{
    if (step == 1)
    {
        step = 2;
    }
    if (step == 3)
    {
        step = 0;
    }

    if (now.toDouble() == 0)
    {
        statusMessage = "Error, can't devide 0";
        clear(true);
        return;
    }

    now.setNum(1.0 / now.toDouble());

    refresh_display();
    return;
}
// 百分号
void MainWindow::on_b_persent_clicked()
{
    if (step == 1)
    {
        step = 2;
    }

    if (step == 3)
    {
        step = 0;
    }

    now.setNum(now.toDouble() / 100);
    refresh_display();
    return;
}

// 正负号
void MainWindow::on_b_p_or_n_clicked()
{
    if (step == 1)
    {
        step = 2;
    }

    if (step == 3)
    {
        step = 0;
    }

    double num = now.toDouble();

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