#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <iostream>

// 回退键
void MainWindow::on_b_backspace_clicked()
{
    bool check;
    double num = now.toDouble(&check);

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
    if (restart_input)
    {
        on_b_c_clicked();
        return;
    }
    now = "0";
    refresh_display();
    return;
}
// C
void MainWindow::on_b_c_clicked()
{
    now = "0";
    operation = "";
    n = 0;
    now = "0";
    restart_input = false;
    refresh_display();
    return;
}
// 等号
void MainWindow::on_b_equal_clicked()
{

    if (operation.isEmpty())
    {
        return;
    } 

    bool check;
    double result = calculate(operation[0], &check);

    n = result;
    now.setNum(result);
    restart_input = true;

    refresh_display();
    return;
}
