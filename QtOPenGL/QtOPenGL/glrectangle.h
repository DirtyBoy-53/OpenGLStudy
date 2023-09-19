#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions_4_5_Compatibility>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QString>

class GLRectangle 
	: public QOpenGLWidget
	, protected QOpenGLFunctions_4_5_Compatibility
{

public:
	GLRectangle(QWidget *parent = nullptr);
	~GLRectangle();

protected:
	void initializeGL() override;
	void paintGL() override;
	void resizeGL(int width, int height) override;

private:
	QOpenGLShaderProgram shaderProgram;
	QOpenGLVertexArrayObject vao;
	QOpenGLBuffer vbo;
	QOpenGLBuffer ebo;
};
