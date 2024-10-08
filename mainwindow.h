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

private:
    void refresh_display();

    Ui::MainWindow *ui;
    QString last;
    QChar operation = 'o';
    QString now = "0";
};
#endif // MAINWINDOW_H
