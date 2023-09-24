#include "gltransform.h"

GLTransform::GLTransform(QWidget *parent)
	: QOpenGLWidget(parent)
{
	connect(&timer, &QTimer::timeout, this, [this]() {
		rotate += 2;
	if (isVisible()) {
		update();
	}
		});
	timer.setInterval(50);
}

GLTransform::~GLTransform()
{
    //initializeGL����ʾʱ�ŵ��ã��ͷ�δ��ʼ���Ļ��쳣
    if (!isValid())
        return;
    //QOpenGLWidget
    //�����麯������ҪmakeCurrent����Ӧ�Ĳ������ɿ�����
    //�����ͷ�ʱ��Ҫ���õ�ǰ������
    makeCurrent();
    vbo.destroy();
    ebo.destroy();
    vao.destroy();
    delete texture1;
    delete texture2;
    doneCurrent();
}
void GLTransform::initializeGL()
{
    //Ϊ��ǰ�����ĳ�ʼ��OpenGL��������
    initializeOpenGLFunctions();

    //��ɫ������
    //in���룬out���,uniform��cpu��gpu����
    //��ΪOpenGL����ߵ������ģ�����ȡ��vec2(aTexCoord.x, 1-aTexCoord.y);
    const char* vertex_str = R"(#version 450 core
    layout (location = 0) in vec3 inPos;
    layout (location = 1) in vec3 inColor;
    layout (location = 2) in vec2 inTexCoord;
    uniform mat4 transform;
    out vec3 theColor;
    out vec2 texCoord;
    void main() {
        gl_Position = transform*vec4(inPos, 1.0);
        theColor = inColor;
        texCoord = vec2(inTexCoord.x, 1-inTexCoord.y);
    })";
    const char* fragment_str = R"(#version 450 core
    in vec3 theColor;
    in vec2 texCoord;
    uniform sampler2D texture1;
    uniform sampler2D texture2;
    out vec4 fragColor;
    void main() {
        fragColor = mix(texture(texture1, texCoord),
        texture(texture2, texCoord), 0.2) * vec4(theColor, 1.0);
    })";

    //��source����Ϊָ�����͵���ɫ��������ӵ�����ɫ������
    if (!shaderProgram.addCacheableShaderFromSourceCode(
        QOpenGLShader::Vertex, vertex_str)) {
        qDebug() << "compiler vertex error" << shaderProgram.log();
    }
    if (!shaderProgram.addCacheableShaderFromSourceCode(
        QOpenGLShader::Fragment, fragment_str)) {
        qDebug() << "compiler fragment error" << shaderProgram.log();
    }
    //ʹ��addShader()����ӵ��ó������ɫ��������һ��
    if (!shaderProgram.link()) {
        qDebug() << "link shaderprogram error" << shaderProgram.log();
    }

    //��������
    float vertices[] = {
        // positions          // colors           // texture coords
        0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
        0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left
    };
    //����
    unsigned int indices[] = {
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };
    vao.create();
    vao.bind();
    //QOpenGLVertexArrayObject::Binder vaoBind(&vao);
    vbo = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    vbo.create();
    vbo.bind();
    vbo.allocate(vertices, sizeof(vertices));

    ebo = QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
    ebo.create();
    ebo.bind();
    ebo.allocate(indices, sizeof(indices));

    //����1��Ӧlayout
    // position attribute
    shaderProgram.setAttributeBuffer(0, GL_FLOAT, 0, 3, sizeof(GLfloat) * 8);
    shaderProgram.enableAttributeArray(0);
    // color attribute
    shaderProgram.setAttributeBuffer(1, GL_FLOAT, sizeof(GLfloat) * 3, 3, sizeof(GLfloat) * 8);
    shaderProgram.enableAttributeArray(1);
    // texture coord attribute
    shaderProgram.setAttributeBuffer(2, GL_FLOAT, sizeof(GLfloat) * 6, 2, sizeof(GLfloat) * 8);
    shaderProgram.enableAttributeArray(2);

    // texture 1
    //ֱ�����ɰ�һ��2d����, �����ɶ༶����MipMaps
    texture1 = new QOpenGLTexture(QImage(":/Image/container.jpg"), QOpenGLTexture::GenerateMipMaps);
    if (!texture1->isCreated()) {
        qDebug() << "Failed to load texture";
    }
    // set the texture wrapping parameters
    // ����glTexParameteri(GLtexture_2D, GLtexture_WRAP_S, GL_REPEAT);
    texture1->setWrapMode(QOpenGLTexture::DirectionS, QOpenGLTexture::Repeat);
    texture1->setWrapMode(QOpenGLTexture::DirectionT, QOpenGLTexture::Repeat);
    // set texture filtering parameters
    //�ȼ���glTexParameteri(GLtexture_2D, GLtexture_MIN_FILTER, GL_LINEAR);
    texture1->setMinificationFilter(QOpenGLTexture::Linear);
    texture1->setMagnificationFilter(QOpenGLTexture::Linear);

    // texture 2
    //ֱ�����ɰ�һ��2d����, �����ɶ༶����MipMaps
    texture2 = new QOpenGLTexture(QImage(":/Image/awesomeface.png"), QOpenGLTexture::GenerateMipMaps);
    if (!texture2->isCreated()) {
        qDebug() << "Failed to load texture";
    }
    // set the texture wrapping parameters
    // ����glTexParameteri(GLtexture_2D, GLtexture_WRAP_S, GL_REPEAT);
    texture2->setWrapMode(QOpenGLTexture::DirectionS, QOpenGLTexture::Repeat);
    texture2->setWrapMode(QOpenGLTexture::DirectionT, QOpenGLTexture::Repeat);//
    // set texture filtering parameters
    //�ȼ���glTexParameteri(GLtexture_2D, GLtexture_MIN_FILTER, GL_LINEAR);
    texture2->setMinificationFilter(QOpenGLTexture::Linear);
    texture2->setMagnificationFilter(QOpenGLTexture::Linear);

    shaderProgram.bind();
    shaderProgram.setUniformValue("texture1", 0);
    shaderProgram.setUniformValue("texture2", 1);
    shaderProgram.release();

    timer.start();
}
void GLTransform::paintGL()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //����
    glActiveTexture(GL_TEXTURE0);
    texture1->bind();
    glActiveTexture(GL_TEXTURE1);
    texture2->bind();
    //�任����
    QMatrix4x4 transform;
    //ƽ��
    transform.translate(QVector3D(0.5f, 0.5f, 0.0f));
    //��ת
    transform.rotate(rotate, QVector3D(0.0f, 1.0f, 0.0f));

    shaderProgram.bind();
    shaderProgram.setUniformValue("transform", transform);
    vao.bind();

    //������������
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
void GLTransform::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
}
