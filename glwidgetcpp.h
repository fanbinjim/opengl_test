#ifndef GLWIDGETCPP_H
#define GLWIDGETCPP_H

#include <QGLWidget>
#include <QTimer>

class glwidgetcpp : public QGLWidget
{
    Q_OBJECT

public:
    explicit glwidgetcpp(QWidget *parent = 0);

    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

    int R;
    float x,y,z;
    double cx, cy, cz;
    bool wired;
    float ang;

private:
    QTimer timer;

private:
    int lastx, lasty;
    Qt::MouseButton pressedMouseButton;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

signals:
    void updateParams();
};

#endif // GLWIDGETCPP_H
