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
private slots:
    void on_num_clicked();
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
    void keyPressEvent(QKeyEvent *event);

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
