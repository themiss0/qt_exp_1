#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <iostream>

// 刷新输出
void MainWindow::refresh_display()
{

    ui->statusbar->showMessage(statusMessage);
    ui->display->setText(now);
}

// 运算函数
double MainWindow::calculate(QChar ch, bool *re)
{

    bool check;

    switch (ch.unicode())
    {
    case '+':
        *re = true;
        return n1 + n2;

    case '-':
        *re = true;
        return n1 - n2;

    case '*':
        *re = true;
        return n1 * n2;

    case '/':
        if (n2 == 0)
        {
            ui->statusbar->showMessage("Error: 0 can't be devision");
            *re = false;
            return 0;
        }
        else
            return n1 / n2;
    }
}
