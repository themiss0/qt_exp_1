#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <ui_mainwindow.h>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override
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

private slots:
    void
    on_num_clicked();
 
    void on_b_point_clicked();

    void on_b_p_or_n_clicked();

    void on_b_backspace_clicked();

    void on_b_ce_clicked();

    void on_b_c_clicked();

    void on_b_sqrt_clicked();

    void on_b_square_clicked();

    void on_b_fraction_clicked();

    void on_b_persent_clicked();

    void on_b_add_clicked();

    void on_b_sub_clicked();

    void on_b_multi_clicked();

    void on_b_devide_clicked();

    void on_b_equal_clicked();

private:
    void refresh_display(bool = false);
    double calculate();
    void clear(bool = false);
    void operate(QChar);

    Ui::MainWindow *ui;

    // 记录输入值
    double a = 0, b = 0;
    // 记录操作符
    QString operation = "";
    // 输入框
    QString now = "0";
    // 状态栏显示
    QString statusMessage = "";
    // 当前步骤
    int step = 0;
};
#endif // MAINWINDOW_H
