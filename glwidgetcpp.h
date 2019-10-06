#ifndef GLWIDGETCPP_H
#define GLWIDGETCPP_H

#include <QGLWidget>
#include <QTimer>

class glwidgetcpp : public QGLWidget
{
public:
    explicit glwidgetcpp(QWidget *parent = 0);

    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

    int R;
    float x,y,z;
    bool wired;
    float ang;
private:
    QTimer timer;
};

#endif // GLWIDGETCPP_H
