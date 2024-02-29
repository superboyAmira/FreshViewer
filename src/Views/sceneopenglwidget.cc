#include "sceneopenglwidget.h"

SceneOpenGlWidget::SceneOpenGlWidget(QWidget *parent)
    : QOpenGLWidget{parent}
{}

void SceneOpenGlWidget::initializeGL() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0,0.0,0.0,1.0);
};

void SceneOpenGlWidget::resizeGL(int width, int height) {
    glViewport(0,0,width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1,1,-1,1,1,2);
};

void SceneOpenGlWidget::paintGL() {
    glClearColor(0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslated(0, 0, 1.0);

    // glVertexPointer(3, GL_DOUBLE, 0, )
    // glRotated(xRot, 1, 0, 0);
    // glRotated(yRot, 0, 1, 0);




};
