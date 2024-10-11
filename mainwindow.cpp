#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <iostream>

// 构造函数
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->b_0, SIGNAL(clicked()), this, SLOT(on_num_clicked()));
    connect(ui->b_1, SIGNAL(clicked()), this, SLOT(on_num_clicked()));
    connect(ui->b_2, SIGNAL(clicked()), this, SLOT(on_num_clicked()));
    connect(ui->b_3, SIGNAL(clicked()), this, SLOT(on_num_clicked()));
    connect(ui->b_4, SIGNAL(clicked()), this, SLOT(on_num_clicked()));
    connect(ui->b_5, SIGNAL(clicked()), this, SLOT(on_num_clicked()));
    connect(ui->b_6, SIGNAL(clicked()), this, SLOT(on_num_clicked()));
    connect(ui->b_7, SIGNAL(clicked()), this, SLOT(on_num_clicked()));
    connect(ui->b_8, SIGNAL(clicked()), this, SLOT(on_num_clicked()));
    connect(ui->b_9, SIGNAL(clicked()), this, SLOT(on_num_clicked()));
}

// 析构
MainWindow::~MainWindow()
{
    delete ui;
}

// 槽函数

void MainWindow::on_num_clicked()
{

    if (now.toDouble() == 0 && !now.contains('.'))
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

void MainWindow::on_b_point_clicked()
{
    if (now.contains('.'))
    {
        return;
    }

    now.append('.');
    refresh_display();
    return;
}

void MainWindow::on_b_p_or_n_clicked()
{
    bool check;
    double num = now.toDouble(&check);
    if (!check)
    {
        ui->statusbar->showMessage("Error on button p_or_n: " + now);
        return;
    }
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

void MainWindow::on_b_backspace_clicked()
{
    bool check;
    double num = now.toDouble(&check);
    if (!check)
    {
        ui->statusbar->showMessage("Error on button_backspace");
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
    if (now.length() == 2 && num == 0)
    {
        now = "0";
        refresh_display();
        return;
    }
    refresh_display();
    return;
}

void MainWindow::on_b_ce_clicked()
{
    now = "0";
    refresh_display();
    return;
}

void MainWindow::on_b_c_clicked()
{
    now = "0";
    operation = 'o';
    last = "0";
    result = "";
    refresh_display();
    return;
}

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

void MainWindow::on_b_add_clicked()
{

    bool check;
    double num = now.toDouble(&check);
    if (!check)
    {
        ui->statusbar->showMessage("Error on button_add");
        return;
    }

    if (num != 0 && operation != 'o')
    {
        double re = calculate(operation, &check);
        last.setNum(re);
    }

    operation = '+';
    last = now;
    now = "0";

    ui->statusbar->showMessage(last + operation);
    refresh_display();
}

void MainWindow::on_b_equal_clicked()
{

    if (operation == 'o')
    {
        return;
    }

    bool check;
    double result = calculate(operation, &check);

    QString *temp = new QString();
    temp->setNum(result);
    statusMessage.append(*temp);
    delete temp;

    now.setNum(result);

    refresh_display();
    return;
}

void MainWindow::on_b_sub_clicked()
{
}

void MainWindow::on_b_multi_clicked()
{
}

void MainWindow::on_b_devide_clicked()
{
}
