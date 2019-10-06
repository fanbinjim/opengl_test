#include "glwidgetcpp.h"
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/gl.h>

glwidgetcpp::glwidgetcpp(QWidget *parent) : QGLWidget(parent)
{
    this->R = 1;
    this->wired = true;
    this->x = 0;
    this->y = 0;
    this->z = 0;

    connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer.start(10);
}

void glwidgetcpp::initializeGL()
{
    glClearColor(0.2f, 0.2f, 0.2f, 1);
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
    gluLookAt(0, 0, 5,  0, 0, 0,  0, 1, 0);
    glTranslatef(x, y, z);
    ang += 1;
    glRotatef(ang, 1, 1, 1);
    glColor3f(1, 0, 0);
    if(wired)
    {
        glutWireSphere(R, 30, 30);
    }
    else
    {
        glutSolidSphere(R, 30, 30);
    }
    GLdouble size = GLdouble(2);
    glutWireCube(size);

}

void glwidgetcpp::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, w/h, 0.01, 100.0);
    updateGL();
}
