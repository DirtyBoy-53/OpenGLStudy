#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions_4_5_Compatibility>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLTexture>
#include <QOpenGLShaderProgram>


//����Ԫ
//QOpenGLWidget����������
//QOpenGLFunctions����OpenGL�ӿڣ����Բ��̳���Ϊ��Ա����ʹ��
class GLTextureUnit
    : public QOpenGLWidget
    , protected QOpenGLFunctions_4_5_Compatibility
{
public:
    explicit GLTextureUnit(QWidget* parent = nullptr);
    ~GLTextureUnit();

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
};
