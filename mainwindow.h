#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void refresh_display();
    double calculate(QChar, bool *);

    Ui::MainWindow *ui;

    // 记录第一个输入
    QString last = "";
    // 记录操作符
    QChar operation = 'o';
    // 记录当前输入
    QString now = "0";
    // 状态栏显示
    QString statusMessage = "";
    // 输出
    QString result = "";
    // 是否已经输出结果
    bool ifOutput = false;
};
#endif // MAINWINDOW_H
