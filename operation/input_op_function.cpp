#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <iostream>

// 数字键
void MainWindow::on_num_clicked()
{

    if (step == 1)
    {
        step = 2;
        now = "0";
        refresh_display();
    }

    if (step == 3)
    {
        step = 0;
        clear();
    }

    if ((now.toDouble() == 0 && !now.contains('.')))
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
// 点号
void MainWindow::on_b_point_clicked()
{

    if (step == 3)
    {
        step = 0;
        now = "0.";
        refresh_display();
        return;
    }

    if (step == 1)
    {
        step = 2;
        now = "0.";
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
