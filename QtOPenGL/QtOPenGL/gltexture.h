#pragma once

#include <QOpenGLWidget>
#include <qopenglfunctions_4_5_compatibility.h>
#include <QOpenGLSHaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLTexture>

class GLTexture  
	: public QOpenGLWidget
	, protected QOpenGLFunctions_4_5_Compatibility
{
public:
	GLTexture(QWidget *parent);
	~GLTexture();

protected:
	void initializeGL() override;
	void paintGL() override;
	void resizeGL(int width, int height) override;

private:
	void checkShaderError(GLuint id, const QString& type);

private:
	GLuint shaderProgram{ 0 };
	GLuint vao{ 0 };
	GLuint vbo{ 0 };
	GLuint ebo{ 0 };
	GLuint texture{ 0 };

};
