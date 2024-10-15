#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <iostream>

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
