#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <iostream>
#include <qfile.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    std::cout << "hello world" << std::endl;
    ui->setupUi(this);

    {
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

    setFocusPolicy(Qt::StrongFocus);
    setWindowIcon(QIcon("://calculate.ico"));

    QFile file(":/styleFile/qss/QPushButton.qss"); // 创建QFile对象的实例
    if (file.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream in(&file);
        QString styleSheet = in.readAll(); // 读取文件内容
        std::cout << "qss:" << std::endl
                  << styleSheet.toStdString() << std::endl;

        this->setStyleSheet(styleSheet); // 假设这是在QWidget派生类中
        file.close();
    }
    else
    {
        std::cout << "fail to open qss" << std::endl;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_0:
        ui->b_0->animateClick();
        break;
    case Qt::Key_1:
        ui->b_1->animateClick();
        break;
    case Qt::Key_2:
        ui->b_2->animateClick();
        break;
    case Qt::Key_3:
        ui->b_3->animateClick();
        break;
    case Qt::Key_4:
        ui->b_4->animateClick();
        break;
    case Qt::Key_5:
        ui->b_5->animateClick();
        break;
    case Qt::Key_6:
        ui->b_6->animateClick();
        break;
    case Qt::Key_7:
        ui->b_7->animateClick();
        break;
    case Qt::Key_8:
        ui->b_8->animateClick();
        break;
    case Qt::Key_9:
        ui->b_9->animateClick();
        break;

    case Qt::Key_Percent:
        ui->b_persent->animateClick();
        break;
    case Qt::Key_Delete:
        ui->b_ce->animateClick();
        break;
    case Qt::Key_Escape:
        ui->b_c->animateClick();
        break;
    case Qt::Key_Backspace:
        ui->b_backspace->animateClick();
        break;
    case Qt::Key_R:
        ui->b_fraction->animateClick();
        break;
    case Qt::Key_At:
        ui->b_sqrt->animateClick();
        break;
    case Qt::Key_Slash:
        ui->b_devide->animateClick();
        break;
    case Qt::Key_Asterisk:
        ui->b_multi->animateClick();
        break;
    case Qt::Key_Minus:
        ui->b_sub->animateClick();
        break;
    case Qt::Key_Plus:
        ui->b_add->animateClick();
        break;
    case Qt::Key_F9:
        ui->b_p_or_n->animateClick();
        break;
    case Qt::Key_Period:
        ui->b_point->animateClick();
        break;
    case Qt::Key_Equal:
        ui->b_equal->animateClick();
        break;
    }
}
