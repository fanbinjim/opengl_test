#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    updateWidgetValue();

    ui->hs_x->setValue(static_cast<int>( ui->openGLWidget->x * 10));
    ui->hs_y->setValue(static_cast<int>( ui->openGLWidget->y * 10));
    ui->hs_z->setValue(static_cast<int>( ui->openGLWidget->z * 10));
    ui->hs_r->setValue(static_cast<int>( ui->openGLWidget->R));
    ui->hs_cx->setValue(static_cast<int>(ui->openGLWidget->cx));
    ui->hs_cy->setValue(static_cast<int>(ui->openGLWidget->cy));
    ui->hs_cz->setValue(static_cast<int>(ui->openGLWidget->cz));

    ui->cb_wired->setChecked(ui->openGLWidget->wired);

    void (glwidgetcpp::*updateParamsFunc)();
    updateParamsFunc = &glwidgetcpp::updateParams;
    connect(ui->openGLWidget, updateParamsFunc, this, [=](){
        qDebug() << "update" ;
        ui->hs_x->setValue(static_cast<int>( ui->openGLWidget->x * 10));
        ui->hs_y->setValue(static_cast<int>( ui->openGLWidget->y * 10));
        ui->hs_z->setValue(static_cast<int>( ui->openGLWidget->z * 10));
        ui->hs_r->setValue(static_cast<int>( ui->openGLWidget->R));
        ui->hs_cx->setValue(static_cast<int>(ui->openGLWidget->cx));
        ui->hs_cy->setValue(static_cast<int>(ui->openGLWidget->cy));
        ui->hs_cz->setValue(static_cast<int>(ui->openGLWidget->cz));
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateWidgetValue()
{
    ui->label_x->setText(QString::number(ui->hs_x->value()*0.1));
    ui->label_y->setText(QString::number(ui->hs_y->value()*0.1));
    ui->label_z->setText(QString::number(ui->hs_z->value()*0.1));
    ui->label_r->setText(QString::number(ui->hs_r->value()));
    ui->label_cx->setText(QString::number(ui->hs_cx->value()));
    ui->label_cy->setText(QString::number(ui->hs_cy->value()));
    ui->label_cz->setText(QString::number(ui->hs_cz->value()));

}

void MainWindow::on_hs_x_valueChanged(int value)
{
    updateWidgetValue();
    ui->openGLWidget->x = value * 0.1f;
}

void MainWindow::on_hs_y_valueChanged(int value)
{
    updateWidgetValue();
    ui->openGLWidget->y = value * 0.1f;
}

void MainWindow::on_hs_z_valueChanged(int value)
{
    updateWidgetValue();
    ui->openGLWidget->z = value * 0.1f;
}

void MainWindow::on_hs_r_valueChanged(int value)
{
    updateWidgetValue();
    ui->openGLWidget->R = value;
}

void MainWindow::on_cb_wired_stateChanged(int arg1)
{
    ui->openGLWidget->wired = arg1;

}

void MainWindow::on_hs_cx_valueChanged(int value)
{
    updateWidgetValue();
    ui->openGLWidget->cx = value;
}

void MainWindow::on_hs_cy_valueChanged(int value)
{
    updateWidgetValue();
    ui->openGLWidget->cy = value;
}

void MainWindow::on_hs_cz_valueChanged(int value)
{
    updateWidgetValue();
    ui->openGLWidget->cz = value;
}
