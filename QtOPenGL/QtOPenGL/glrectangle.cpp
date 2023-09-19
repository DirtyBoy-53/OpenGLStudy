#include "glrectangle.h"

GLRectangle::GLRectangle(QWidget *parent)
	: QOpenGLWidget(parent)
{

}

GLRectangle::~GLRectangle()
{
	if (!isValid())
		return;
	makeCurrent();
	vao.destroy();
	vbo.destroy();
	ebo.destroy();
	doneCurrent();
}

void GLRectangle::initializeGL()
{
	initializeOpenGLFunctions();
	const char* vertex_str = R"(#version 450
layout (location = 0) in vec3 vertices;
void main(){
gl_Position = vec4(vertices,1.0);
})";

	const char* fragment_str = R"(#version 450
uniform vec3 myColor;
out vec4 fragColor;
void main(){
fragColor = vec4(myColor,1.0);
})";
	bool success = shaderProgram.addCacheableShaderFromSourceCode(
		QOpenGLShader::Vertex, vertex_str);
	if (!success) {
		qDebug() << "compiler vertex failed!" << shaderProgram.log();
	}
	success = shaderProgram.addCacheableShaderFromSourceCode(QOpenGLShader::Fragment, fragment_str);
	if (!success) {
		qDebug() << "compiler fragment failed!" << shaderProgram.log();
	}

	success = shaderProgram.link();
	if (!success) {
		qDebug() << "link shader failed!" << shaderProgram.log();
	}

	//两个三角组合为矩形
	float vertices[] = {
		0.5f,  0.5f, 0.0f,  // top right
		0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.5f, 0.0f   // top left
	};
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

	int attr{ 0 };
	attr = shaderProgram.attributeLocation("vertices");
	shaderProgram.setAttributeBuffer(attr, GL_FLOAT, 0, 3, sizeof(GLfloat) * 3);
	shaderProgram.enableAttributeArray(attr);

	vao.release();
	vbo.release();

}

void GLRectangle::paintGL()
{
	glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	shaderProgram.bind();
	shaderProgram.setUniformValue("myColor", QVector3D(0.6f, 0.5f, 0.4f));
	
	QOpenGLVertexArrayObject::Binder vao_bind(&vao); Q_UNUSED(vao_bind);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	
	shaderProgram.release();
}

void GLRectangle::resizeGL(int width, int height)
{
	glViewport(0, 0, width, height);
}
