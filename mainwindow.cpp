#include "mainwindow.h"
#include "ui_mainwindow.h"

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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_num_clicked()
{

    if (now.toDouble() == 0)
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

    bool check;
    double num = now.toDouble(&check);
    if (!check)
    {
        ui->statusbar->showMessage("Error on button_point:" + now);
        return;
    }

    if (num == 0)
    {
        return;
    }

    refresh_display();
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
    if (num == 0)
    {
        return;
    }

    if (num < 0)
    {
        now.removeFirst();
    }
    else
    {
        now = "-" + now;
    }
    refresh_display();
}

void MainWindow::refresh_display()
{
    ui->display->setText(now);
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
    if (num == 0){
        return;
    }

    

}
