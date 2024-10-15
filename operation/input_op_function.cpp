#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <iostream>
// 数字键
void MainWindow::on_num_clicked()
{

    if ((now.toDouble() == 0 && !now.contains('.')) || restart_input)
    {
        if (restart_input)
        {
            on_b_c_clicked();
            restart_input = false;
        }
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
// 点号
void MainWindow::on_b_point_clicked()
{

    if (restart_input)
    {
        on_b_c_clicked();
        now = "0.";
        restart_input = false;
        refresh_display();
        return;
    }

    if (now.contains('.'))
    {
        return;
    }

    now.append('.');
    refresh_display();
    return;
}
