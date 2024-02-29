#ifndef SCENEOPENGLWIDGET_H
#define SCENEOPENGLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>

class SceneOpenGlWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit SceneOpenGlWidget(QWidget *parent = nullptr);

signals:

protected:
    void initializeGL() override;
    void resizeGL(int width, int height) override;
    void paintGL() override;
};

#endif // SCENEOPENGLWIDGET_H
