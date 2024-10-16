#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <iostream>

// 刷新输出
void MainWindow::refresh_display(bool iferror)
{
    if (!iferror)
    {
        statusMessage = "a:" + QString::number(a) + ", operation:" + operation + ", b: " + QString::number(b) + ", step:" + QString::number(step);
    }
    ui->statusbar->showMessage(statusMessage);
    ui->display->setText(now);
}

// 运算函数
double MainWindow::calculate()
{

    switch (operation[0].unicode())
    {
    case '+':
        return a + b;

    case '-':
        return a - b;

    case '*':
        return a * b;

    case '/':
        if (b == 0)
        {
            statusMessage = "Error: 0 can't be devision";
            clear(true);
            return 0;
        }
        else
            return a / b;
    }
}

void MainWindow::clear(bool iferror)
{
    now = "0";
    operation = "";
    a = 0;
    b = 0;
    now = "0";
    step = 0;

    refresh_display(iferror);
    return;
}

void MainWindow::operate(QChar op)
{

    if (step == 1)
    {
        operation = op;
        refresh_display();
        return;
    }

    if (step == 0 || step == 3)
    {
        step = 1;
        a = now.toDouble();
        now.setNum(a);
        operation = op;
        refresh_display();
        return;
    }

    step = 1;
    b = now.toDouble();
    a = calculate();
    now.setNum(a);
    operation = op;

    refresh_display();
}
