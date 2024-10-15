#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <iostream>

void MainWindow::refresh_display()
{

    ui->statusbar->showMessage(statusMessage);
    ui->display->setText(now);
}

double MainWindow::calculate(QChar ch, bool *re)
{

    bool check;

    double a = last.toDouble(&check);
    if (!check)
    {
        ui->statusbar->showMessage("Error: calculate a");
        *re = false;
        return 0;
    }
    double b = now.toDouble(&check);
    if (!check)
    {
        ui->statusbar->showMessage("Error: calculate b");
        *re = false;
        return 0;
    }

    switch (ch.unicode())
    {
    case '+':
        *re = true;
        return a + b;

    case '-':
        *re = true;
        return a - b;

    case '*':
        *re = true;
        return a * b;

    case '/':
        if (b == 0)
        {
            ui->statusbar->showMessage("Error: 0 can't be devision");
            *re = false;
            return 0;
        }
        else
            return a / b;
    }
}
