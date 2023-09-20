#include "gltexture.h"

GLTexture::GLTexture(QWidget *parent)
	: QOpenGLWidget(parent)
{}

GLTexture::~GLTexture()
{
	if (!isValid())
		return;
	makeCurrent();
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ebo);
	glDeleteVertexArrays(1, &vao);
	glDeleteTextures(1, &texture);
	glDeleteProgram(shaderProgram);
	doneCurrent();
}

void GLTexture::initializeGL()
{
	initializeOpenGLFunctions();
	const char* vertex_str = R"(#version 450
layout(location = 0) in vec3 inPos;
layout(location = 1) in vec3 inColor;
layout(location = 2) in vec2 inTexCoord;
out vec3 theColor;
out vec2 texCoord;
void main() {
gl_Position = vec4(inPos,1.0);
theColor = inColor;
texCoord = vec2(inTexCoord.x, 1-inTexCoord.y);
})";
	const char* fragment_str = R"(#version 450
uniform sampler2D theTexture;
in vec3 theColor;
in vec2 texCoord;
out vec4 fragColor;
void main() {
fragColor = texture(theTexture, texCoord) * vec4(theColor, 1.0);
})";
	GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vertex_str, NULL);
	glCompileShader(vertex_shader);
	checkShaderError(vertex_shader, "vertex");
	GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fragment_str, NULL);
	glCompileShader(fragment_shader);
	checkShaderError(fragment_shader, "fragment");

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertex_shader);
	glAttachShader(shaderProgram, fragment_shader);
	glLinkProgram(shaderProgram);
	checkShaderError(shaderProgram, "program");
	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);

	float vertices[] = {
		// positions          // colors           // texture coords
		0.5f,  0.5f, 0.0f,   0.1f, 0.2f, 0.3f,   1.0f, 1.0f, // top right
		0.5f, -0.5f, 0.0f,   0.4f, 0.5f, 0.6f,   1.0f, 0.0f, // bottom right
		-0.5f, -0.5f, 0.0f,   0.7f, 0.8f, 0.9f,  0.0f, 0.0f, // bottom left
		-0.5f,  0.5f, 0.0f,   1.0f, 0.1f, 0.2f,  0.0f, 1.0f  // top left
	};
	unsigned int indices[] = {
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};

	glCreateVertexArrays(1, &vao);
	glCreateBuffers(1, &vbo);
	glNamedBufferStorage(vbo, sizeof(vertices), vertices, GL_DYNAMIC_STORAGE_BIT);
	glVertexArrayVertexBuffer(vao, 0, vbo, 0, 8 * sizeof(float));
	glEnableVertexArrayAttrib(vao, 0);
	glEnableVertexArrayAttrib(vao, 1);
	glEnableVertexArrayAttrib(vao, 2);

	glVertexArrayAttribFormat(vao, 0, 3, GL_FLOAT, GL_FALSE, 0);
	glVertexArrayAttribFormat(vao, 1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float));
	glVertexArrayAttribFormat(vao, 2, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float));

	glVertexArrayAttribBinding(vao, 0, 0);
	glVertexArrayAttribBinding(vao, 1, 0);
	glVertexArrayAttribBinding(vao, 2, 0);

	glCreateBuffers(1, &ebo);
	glNamedBufferStorage(ebo, sizeof(indices), indices, GL_DYNAMIC_STORAGE_BIT);
	glVertexArrayElementBuffer(vao, ebo);
	QImage img(":/Image/awesomeface.png");
	img.convertToFormat(QImage::Format_RGB888);
	glCreateTextures(GL_TEXTURE_2D, 1, &texture);
	glTextureParameteri(texture, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTextureParameteri(texture, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glTextureParameteri(texture, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTextureParameteri(texture, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTextureStorage2D(texture, 1, GL_RGBA8, img.width(), img.height());
	glTextureSubImage2D(texture, 0, 0, 0, img.width(), img.height(), GL_RGBA, GL_UNSIGNED_BYTE, img.bits());
}

void GLTexture::paintGL()
{
	glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glUseProgram(shaderProgram);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);

	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void GLTexture::resizeGL(int width, int height)
{
	glViewport(0, 0, width, height);
}

void GLTexture::checkShaderError(GLuint id, const QString& type)
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
