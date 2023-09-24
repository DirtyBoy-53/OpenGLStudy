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
    //�����̳�QOpenGLWidget����д�������麯��
    //����OpenGL��Դ��״̬���ڵ�һ�ε���resizeGL��paintGL֮ǰ������һ��
    void initializeGL() override;
    //��ȾOpenGL������ÿ����Ҫ����С����ʱʹ��
    void paintGL() override;
    //����OpenGL�ӿڡ�ͶӰ�ȣ�ÿ���ߴ��С�ı�ʱ����
    void resizeGL(int width, int height) override;

private:
    //��ɫ������
    QOpenGLShaderProgram shaderProgram;
    //�����������
    QOpenGLVertexArrayObject vao;
    //���㻺��
    QOpenGLBuffer vbo;
    //��������
    QOpenGLBuffer ebo;
    //������Ϊ���ܸ�ֵ������ֻ������Ϊָ�룩
    QOpenGLTexture* texture1{ nullptr };
    QOpenGLTexture* texture2{ nullptr };
    //��ת
    QTimer timer;
    int rotate{ 0 };
};
