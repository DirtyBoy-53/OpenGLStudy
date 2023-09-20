#include "gltriangle.h"
#include <QDebug>
GLTriangle::GLTriangle(QWidget *parent)
	: QOpenGLWidget(parent)
{

}

GLTriangle::~GLTriangle()
{
	if (!isValid())
		return;
	makeCurrent();
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteProgram(shaderProgram);
	doneCurrent();
}

void GLTriangle::initializeGL()
{
	initializeOpenGLFunctions();

	const char* vertex_str = R"(#version 450
	layout (location = 0) in vec3 vertices;
	void main(){
	gl_Position = vec4(vertices,1.0);})";

	const char* fragment_str = R"(#version 450
	uniform vec3 myColor;
	out vec4 fragColor;
	void main(){
	fragColor = vec4(myColor,1.0);
	})";

	GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(vertex_shader, 1, &vertex_str, NULL);
	glShaderSource(fragment_shader, 1, &fragment_str, NULL);
	glCompileShader(vertex_shader);
	glCompileShader(fragment_shader);
	checkShaderError(vertex_shader, "vertex");
	checkShaderError(fragment_shader, "fragment");


	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertex_shader);
	glAttachShader(shaderProgram, fragment_shader);
	glLinkProgram(shaderProgram);
	checkShaderError(shaderProgram, "program");
	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);

	float vertices[] = {
		-0.5f, -0.5f, 0.0f, // left
		0.5f, -0.5f, 0.0f, // right
		0.0f,  0.5f, 0.0f  // top
	};
	glCreateVertexArrays(1, &vao);
	glCreateBuffers(1, &vbo);
	glNamedBufferStorage(vbo, sizeof(vertices), vertices, GL_DYNAMIC_STORAGE_BIT);
	glVertexArrayVertexBuffer(vao, 0, vbo, 0, sizeof(float) * 3);
	glEnableVertexArrayAttrib(vao, 0);
	glVertexArrayAttribFormat(vao, 0, 3, GL_FLOAT, GL_FALSE, 0);
	glVertexArrayAttribBinding(vao, 0, 0);
}

void GLTriangle::paintGL()
{
	glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(shaderProgram);
	glUniform3f(glGetUniformLocation(shaderProgram, "myColor"), 0.6f, 0.5f, 0.4f);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void GLTriangle::resizeGL(int width, int height)
{
	glViewport(0, 0, width, height);
}

void GLTriangle::checkShaderError(GLuint id, const QString& type)
{
	int check_flag;
	char check_info[1024];
	if (type != "program") {
		glGetShaderiv(id, GL_COMPILE_STATUS, &check_flag);
		if (!check_flag) {
			glGetShaderInfoLog(id, 1024, NULL, check_info);
			qDebug() << type << " error:" << check_info;
		}
	}
	else {
		glGetShaderiv(id, GL_LINK_STATUS, &check_flag);
		if (!check_flag) {
			glGetProgramInfoLog(id, 1024, NULL, check_info);
			qDebug() << type << " error:" << check_info;
		}
	}
}
