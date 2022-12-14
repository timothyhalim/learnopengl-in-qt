#include "window.h"

#include <QDebug>

const char* const vertexShaderSource =
"#version 330 core \n"

"layout (location = 0) in vec3 position;\n"

"void main()\n"
"{\n"
"    gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
"}";

const char *const fragmentShaderSource =
"#version 330 core\n"

"out vec4 color;\n"

"void main()\n"
"{\n"
"    color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}"
;

Window::Window()
{
    resize(640, 480);
}

void Window::initializeGL()
{
    initializeOpenGLFunctions();
    qInfo() << "real OGL version" << reinterpret_cast<const char *>(glGetString(GL_VERSION));

    initializeGeometry();
    initializeShaders();
}

void Window::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void Window::paintGL()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    m_program->bind();
    QOpenGLVertexArrayObject::Binder vaoBinder(&m_vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    m_program->release();
}

void Window::initializeGeometry()
{
    // setup vertex data

    GLfloat vertices[] = {
        // Positions
        0.5f, -0.5f, 0.0f,  // Bottom right corner
        -0.5f, -0.5f, 0.0f, // Bottom left corner
        0.0f,  0.5f, 0.0f,  // Top corner
    };

    m_vao.create();
    QOpenGLVertexArrayObject::Binder vaoBinder(&m_vao);

    m_vbo.create();
    m_vbo.bind();
    m_vbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
    m_vbo.allocate(vertices, sizeof(vertices));

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
}

void Window::initializeShaders()
{
    m_program = std::make_unique<QOpenGLShaderProgram>();
    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    m_program->link();
}
