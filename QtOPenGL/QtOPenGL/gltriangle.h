#pragma once
#include <QOpenGLWidget>
#include <QOpenGLFunctions_4_5_Compatibility>
#include <QString>
class GLTriangle  
	: public QOpenGLWidget
	, protected QOpenGLFunctions_4_5_Compatibility
{
public:
	explicit GLTriangle(QWidget *parent = nullptr);
	~GLTriangle();
protected:
	void initializeGL() override;
	void paintGL() override;
	void resizeGL(int width, int height) override;
private:
	void checkShaderError(GLuint id, const QString& type);
private:
	//还没使用Qt的封装
	GLuint shaderProgram{ 0 };
	GLuint vao{ 0 };
	GLuint vbo{ 0 };
};
