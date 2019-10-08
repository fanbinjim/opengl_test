#include "glwidgetcpp.h"
#include <QMouseEvent>
#include <QWheelEvent>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#include <QDebug>

glwidgetcpp::glwidgetcpp(QWidget *parent) : QGLWidget(parent)
{
    this->R = 1;
    this->wired = false;
    this->x = 0;
    this->y = 0;
    this->z = 0;

    this->cx = 45;
    this->cy = 20;
    this->cz = 25;

    connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer.start(10);
}

void glwidgetcpp::initializeGL()
{
    glClearColor(1, 1, 1, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
}

void glwidgetcpp::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    double theta = 0;
    double radius = 0;
    double gama = 0;
    radius = cy;
    theta = cx;
    gama = cz;

    double realX, realY, realZ;

    realX = radius * cos(theta / 180 * 3.1415);
    realY = radius * sin(theta / 180 * 3.1415);
    realX = realX * cos(gama / 180 * 3.1415);
    realY = realY * cos(gama / 180 * 3.1415);
    realZ = radius * sin(gama / 180 * 3.1415);

    gluLookAt(realX, realY, realZ,  0, 0, 0,  0, 0, 1);

    glTranslatef(0,0,0);
    glLineWidth(2.0f);

    glBegin(GL_LINES);
    // x
    glVertex3f(0,0,0);
    glVertex3f(5, 0, 0);
    // y
    glVertex3f(0,0,0);
    glVertex3f(0, 5, 0);
    // z
    glVertex3f(0,0,0);
    glVertex3f(0, 0, 5);

    for(int i = 0; i < 5; i ++)
    {
        glVertex3f(i,0,0);
        glVertex3f(i+1,0,0);
        glVertex3f(i+1,5,0);
        glVertex3f(i+1,0,0);
        glVertex3f(0,0,0);

        glVertex3f(0,i,0);
        glVertex3f(0,i+1,0);
        glVertex3f(5,i+1,0);
        glVertex3f(0,i+1,0);
        glVertex3f(0,0,0);
    }

    glEnd();


    glTranslatef(0, 0, 0);
    //ang += 1;
    //glRotatef(ang, 1, 1, 1);

    glRotatef(x, 1, 0, 0);
    glRotatef(y, 0, 1, 0);
    glRotatef(z, 0, 0, 1);



    glColor3f(1, 0, 0);
    GLdouble size = GLdouble(2);
    if(wired)
    {
        glutWireSphere(R, 30, 30);
        glTranslatef(2, 0, 0);
        glutWireCube(size);
    }
    else
    {
        glutSolidSphere(R, 30, 30);
        glTranslatef(2, 0, 0);
        glutSolidCube(size);
    }

    glTranslatef(-2, 0, 2);
    glutSolidSphere(0.1, 30, 30);


}

void glwidgetcpp::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, w/h, 0.01, 100.0);
    updateGL();
}

void glwidgetcpp::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "mouse press: x: " << event->x() << " y: " << event->y();
    this->lastx = event->x();
    this->lasty = event->y();
    pressedMouseButton = event->button(); // ;
}

void glwidgetcpp::mouseReleaseEvent(QMouseEvent *event)
{
    if(pressedMouseButton == Qt::MouseButton::LeftButton) {
        int detX,detY;
        detX = event->x() - this->lastx;
        detY = event->y() - this->lasty;

        this->cx += detX * 0.001;
        this->cz += detY * 0.001;

        this->lastx = event->x();
        this->lasty = event->y();

        qDebug() << "mouse release: theta: " << this->cx << " gamma: " << this->cz;


        emit this->updateParams();
    }
}

void glwidgetcpp::mouseMoveEvent(QMouseEvent *event)
{
    if(pressedMouseButton == Qt::MouseButton::LeftButton) {
        int detX,detY;
        detX = event->x() - lastx;
        detY = event->y() - lasty;

        this->cx -= detX ;
        this->cz += detY ;
        if(this->cz > 90) {
            this->cz = 90;
        }
        if(this->cz < -90) {
            this->cz = -90;
        }

        this->lastx = event->x();
        this->lasty = event->y();

        qDebug() << "mouse move: theta: " << this->cx << " gamma: " << this->cz;

        emit updateParams();
    }
}

void glwidgetcpp::wheelEvent(QWheelEvent *event)
{
    qDebug() << "wheel event: " << event->angleDelta().y() / 1200.0;
    this->cy -= event->angleDelta().y() / 120.0;
    if(this->cy < 3) {
        this->cy = 3;
    }
    if(this->cy > 20) {
        this->cy = 20;
    }
    emit updateParams();
}
