#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions_4_5_Core>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLTexture>
#include <QTimer>
class GLTransform  
	: public QOpenGLWidget
	, protected QOpenGLFunctions_4_5_Core
{
public:
	GLTransform(QWidget *parent=nullptr);
	~GLTransform();
protected:
    //【】继承QOpenGLWidget后重写这三个虚函数
    //设置OpenGL资源和状态。在第一次调用resizeGL或paintGL之前被调用一次
    void initializeGL() override;
    //渲染OpenGL场景，每当需要更新小部件时使用
    void paintGL() override;
    //设置OpenGL视口、投影等，每当尺寸大小改变时调用
    void resizeGL(int width, int height) override;

private:
    //着色器程序
    QOpenGLShaderProgram shaderProgram;
    //顶点数组对象
    QOpenGLVertexArrayObject vao;
    //顶点缓冲
    QOpenGLBuffer vbo;
    //索引缓冲
    QOpenGLBuffer ebo;
    //纹理（因为不能赋值，所以只能声明为指针）
    QOpenGLTexture* texture1{ nullptr };
    QOpenGLTexture* texture2{ nullptr };
    //旋转
    QTimer timer;
    int rotate{ 0 };
};
