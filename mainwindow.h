#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_hs_x_valueChanged(int value);

    void on_hs_y_valueChanged(int value);

    void on_hs_z_valueChanged(int value);

    void on_hs_r_valueChanged(int value);

    void on_cb_wired_stateChanged(int arg1);

    void on_hs_cx_valueChanged(int value);

    void on_hs_cy_valueChanged(int value);

    void on_hs_cz_valueChanged(int value);

private:
    Ui::MainWindow *ui;

    void updateWidgetValue();

};

#endif // MAINWINDOW_H
