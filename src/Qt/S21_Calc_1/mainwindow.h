#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <sstream>
#include <iomanip>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_PLOT_clicked();
    void digits_press();
    void bin_press();
    void trig_press();
    void on_point_clicked();
    void on_AC_clicked();
    void on_equal_clicked();


private:
    Ui::MainWindow *ui;
    int got_res = 0;
};
#endif // MAINWINDOW_H

