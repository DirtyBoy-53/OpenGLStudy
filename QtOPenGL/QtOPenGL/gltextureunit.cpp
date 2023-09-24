#include "gltextureunit.h"
#include <QDebug>

GLTextureUnit::GLTextureUnit(QWidget* parent)
    : QOpenGLWidget(parent)
{}

GLTextureUnit::~GLTextureUnit()
{
    if (!isValid()) return;
    makeCurrent();
    vao.destroy();
    vbo.destroy();
    ebo.destroy();
    delete texture1;
    delete texture2;
    doneCurrent();
}

void GLTextureUnit::initializeGL()
{
    initializeOpenGLFunctions();
    const char* vertex_str = R"(
    #version 450 core
    layout (location = 0) in vec3 inPos;
    layout (location = 1) in vec2 inTexCoord;
    out vec2 texCoord;
    void main(){
        gl_Position = vec4(inPos,1.0);
        texCoord = vec2(inTexCoord.x,1-inTexCoord.y);
    })";
    const char* fragment_str = R"(
    #version 450 core
    uniform sampler2D texture1;
    uniform sampler2D texture2;
    in vec2 texCoord;
    out vec4 fragColor;
    void main(){
        fragColor = mix(texture(texture1,texCoord),texture(texture2,texCoord),0.2);
    })";

    if (!shaderProgram.addCacheableShaderFromSourceCode(
        QOpenGLShader::Vertex, vertex_str)) {
        qDebug() << "compiler vertex error:" << shaderProgram.log();
    }
    if (!shaderProgram.addCacheableShaderFromSourceCode(
        QOpenGLShader::Fragment, fragment_str)) {
        qDebug() << "compiler fragment error:" << shaderProgram.log();
    }
    shaderProgram.link();
    if (!shaderProgram.link()) {
        qDebug() << "link shaderprogram error" << shaderProgram.log();
    }
    //顶点数据
    float vertices[] = {
        // positions          // texture coords
        0.5f,  0.5f, 0.0f,   1.0f, 1.0f, // top right
        0.5f, -0.5f, 0.0f,   1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f,  0.0f, 1.0f  // top left
    };
    //索引
    unsigned int indices[] = {
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };

    vao.create();
    vao.bind();
    vbo = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    vbo.create();
    vbo.bind();
    vbo.allocate(vertices, sizeof(vertices));
    ebo = QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
    ebo.create();
    ebo.bind();
    ebo.allocate(indices, sizeof(indices));

    int attr{ -1 };
    attr = shaderProgram.attributeLocation("inPos");
    shaderProgram.setAttributeBuffer(attr, GL_FLOAT, 0, 3, sizeof(GLfloat) * 5);
    shaderProgram.enableAttributeArray(attr);

    attr = shaderProgram.attributeLocation("inTexCoord");
    shaderProgram.setAttributeBuffer(attr, GL_FLOAT, sizeof(GLfloat) * 3, 2, sizeof(GLfloat) * 5);
    shaderProgram.enableAttributeArray(attr);

    texture1 = new QOpenGLTexture(QImage(":/Image/container2.png"), QOpenGLTexture::GenerateMipMaps);
    if (!texture1->isCreated()) {
        qDebug() << "Failed to load texture1";
    }
    texture1->setWrapMode(QOpenGLTexture::Repeat);
    texture1->setMinificationFilter(QOpenGLTexture::Linear);
    texture1->setMagnificationFilter(QOpenGLTexture::Linear);
    texture2 = new QOpenGLTexture(QImage(":/Image/awesomeface.png"), QOpenGLTexture::GenerateMipMaps);
    if (!texture2->isCreated()) {
        qDebug() << "Failed to load texture2";
    }
    texture2->setWrapMode(QOpenGLTexture::Repeat);
    texture2->setMinificationFilter(QOpenGLTexture::Linear);
    texture2->setMagnificationFilter(QOpenGLTexture::Linear);

    shaderProgram.bind();
    shaderProgram.setUniformValue("texture1", 0);
    shaderProgram.setUniformValue("texture2", 1);
    shaderProgram.release();
}

void GLTextureUnit::paintGL()
{
    glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glActiveTexture(GL_TEXTURE0);

    texture1->bind();
    glActiveTexture(GL_TEXTURE1);

    texture2->bind();
    shaderProgram.bind();
    vao.bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    shaderProgram.release();
}

void GLTextureUnit::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
}
