#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <iostream>

// 回退键
void MainWindow::on_b_backspace_clicked()
{
    double num = now.toDouble();

    if (step == 3 || step == 1)
    {
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
    // 如果是-0
    if (now.length() == 2 && num == 0)
    {
        now = "0";
        refresh_display();
        return;
    }
    refresh_display();
    return;
}
// CE

void MainWindow::on_b_ce_clicked()
{
    if (step == 3)
    {
        clear();
        return;
    }

    now = "0";
    refresh_display();
    return;
}
// C
void MainWindow::on_b_c_clicked()
{
    clear();
}
// 等号
void MainWindow::on_b_equal_clicked()
{

    if (step == 0)
    {
        step = 3;
        operation = "";
        a = now.toDouble();
        now.setNum(a);

        refresh_display();
        return;
    }

    if (step == 1)
    {
        step = 3;
        a = now.toDouble();
        b = now.toDouble();
        now.setNum(calculate());
        refresh_display();
        return;
    }

    if (step == 2)
    {
        step = 3;
        b = now.toDouble();
        now.setNum(calculate());
        refresh_display();
        return;
    }

    if (operation.isEmpty())
    {
        refresh_display();
        return;
    }
    a = now.toDouble();
    now.setNum(calculate());

    refresh_display();
    return;
}
