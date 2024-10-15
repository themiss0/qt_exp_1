#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <iostream>


// 平方根
void MainWindow::on_b_sqrt_clicked()
{
    bool check;
    double num = now.toDouble(&check);
    std::cout << num;
    if (!check)
    {
        ui->statusbar->showMessage("Error on button_sqrt");
        return;
    }

    now.setNum(sqrt(num));
    refresh_display();
    return;
}
// 平方
void MainWindow::on_b_square_clicked()

{
    bool check;
    double num = now.toDouble(&check);
    std::cout << num;
    if (!check)
    {
        ui->statusbar->showMessage("Error on button_squard");
        return;
    }

    now.setNum(pow(num, 2));
    refresh_display();
    return;
}
// 倒数
void MainWindow::on_b_fraction_clicked()
{

    bool check;
    double num = now.toDouble(&check);
    std::cout << num;
    if (!check)
    {
        ui->statusbar->showMessage("Error on button_squard");
        return;
    }

    now.setNum(1.0 / num);
    refresh_display();
    return;
}
// 百分号
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

// 正负号
void MainWindow::on_b_p_or_n_clicked()
{
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