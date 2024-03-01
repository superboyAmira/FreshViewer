#include "viewopenglscene.h"
#include <QDebug>

s21::ViewOpenGLScene::ViewOpenGLScene(QWidget *parent)
    : QOpenGLWidget{parent}
{
    zoom = -1.0;
    xRot = 0;
    yRot = 0;
}

void s21::ViewOpenGLScene::SetVertices(std::vector<double>& ver) {
    vertices_.clear();
    vertices_ = ver;
};

void s21::ViewOpenGLScene::SetLines(std::vector<int>& lines) {
    lines_.clear();
    lines_ = lines;
    update();
};

void s21::ViewOpenGLScene::initializeGL() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0,0.0,0.0,1.0);
};

void s21::ViewOpenGLScene::resizeGL(int width, int height) {
    glViewport(0,0,width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1,1,-1,1,1, 10000);
};

void s21::ViewOpenGLScene::paintGL() {
    glClearColor(0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if (vertices_.size() == 0) {
        return;
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslated(0, 0, zoom);
    glRotated(xRot, 1, 0, 0);
    glRotated(yRot, 0, 1, 0);

    glVertexPointer(3, GL_DOUBLE, 0, vertices_.data());
    glEnableClientState(GL_VERTEX_ARRAY);
        glColor3d(1.0,0.0,0.0);
    glDrawElements(GL_LINES, lines_.size(), GL_UNSIGNED_INT, lines_.data());
        glColor3d(0.0,0.0,1.0);

    // glEnable(GL_POINT_SMOOTH);
    glPointSize(8);

    glDrawArrays(GL_POINTS, 0, vertices_.size() / 3);

    // glDisable(GL_POINT_SMOOTH);

    glDisableClientState(GL_VERTEX_ARRAY);
};

void s21::ViewOpenGLScene::mouseMoveEvent(QMouseEvent *mo) {
    xRot = 1 / M_PI * (mo->pos().y() - mPos.y());
    yRot = 1 / M_PI * (mo->pos().x() - mPos.x());
    update();
}

void s21::ViewOpenGLScene::mousePressEvent(QMouseEvent *mo) {
    mPos = mo->pos();
}

void s21::ViewOpenGLScene::wheelEvent(QWheelEvent *wh) {
    QPoint numDegrees = wh->angleDelta();
    if (numDegrees.y() > 0)
        zoom = zoom / 1.3;
    else if (numDegrees.y() < 0)
        zoom = zoom * 1.3;
    update();
}
