#include "window.h"

#include <QDebug>

Window::Window()
{
    resize(640, 480);
}

void Window::initializeGL()
{   
    qDebug() << "Initialize GL";
    initializeOpenGLFunctions();
    qInfo() << "real OGL version" << reinterpret_cast<const char *>(glGetString(GL_VERSION));
}

void Window::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void Window::paintGL()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

