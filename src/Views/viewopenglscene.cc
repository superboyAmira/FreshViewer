#include "viewopenglscene.h"

#include <QDebug>
#define _USE_MATH_DEFINES
#include <cmath>
s21::ViewOpenGLScene::ViewOpenGLScene(QWidget *parent) : QOpenGLWidget{parent} {
  // state_.clear();
  if (!state_.contains("projection_type")) {
    SetDefault();
  }
  zoom = -1.0;
  xRot = 0;
  yRot = 0;
}

void s21::ViewOpenGLScene::SetVertices(std::vector<double> &ver) {
  vertices_.clear();
  vertices_ = ver;
};

void s21::ViewOpenGLScene::SetLines(std::vector<int> &lines) {
  lines_.clear();
  lines_ = lines;
  update();
};

QSettings *s21::ViewOpenGLScene::GetState() { return &state_; };

void s21::ViewOpenGLScene::initializeGL() {
  glEnable(GL_DEPTH_TEST);
  glClearColor(state_.value("projection_colorR").toDouble(),
               state_.value("projection_colorG").toDouble(),
               state_.value("projection_colorB").toDouble(), 1.0);
};

void s21::ViewOpenGLScene::resizeGL(int width, int height) {
  glViewport(0, 0, width, height);
};

void s21::ViewOpenGLScene::paintGL() {
  glClearColor(state_.value("projection_colorR").toDouble(),
               state_.value("projection_colorG").toDouble(),
               state_.value("projection_colorB").toDouble(), 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  if (vertices_.size() == 0) {
    return;
  }

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (state_.value("projection_type").toInt() == CENTRAL) {
    glFrustum(-1, 1, -1, 1, 1, 1000000);
  } else {
    glOrtho(-4, 4, -4, 4, -3, 1000000);
  }

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslated(0, 0, zoom);
  glRotated(xRot, 1, 0, 0);
  glRotated(yRot, 0, 1, 0);

  glVertexPointer(3, GL_DOUBLE, 0, vertices_.data());
  glEnableClientState(GL_VERTEX_ARRAY);
  switch (state_.value("lines_type").toInt()) {
    case 1:
      glEnable(GL_LINE_STIPPLE);
      glLineStipple(3, 0xAAAA);
      break;
    case 0:
    default:
      glDisable(GL_LINE_STIPPLE);
      break;
  }
  glLineWidth(state_.value("lines_size").toInt());
  glColor3d(state_.value("lines_colorR").toDouble(),
            state_.value("lines_colorG").toDouble(),
            state_.value("lines_colorB").toDouble());
  glDrawElements(GL_LINES, lines_.size(), GL_UNSIGNED_INT, lines_.data());

  switch (state_.value("vertices_type").toInt()) {
    case 2:
      break;
    case 1:
      glEnable(GL_POINT_SMOOTH);
    case 0:
    default:
      glColor3d(state_.value("vertices_colorR").toDouble(),
                state_.value("vertices_colorG").toDouble(),
                state_.value("vertices_colorB").toDouble());
      glPointSize(state_.value("vertices_size").toInt());
      glDrawArrays(GL_POINTS, 0, vertices_.size() / 3);
      break;
  }
  if (state_.value("vertices_type").toInt() == ROUNDED) {
    glDisable(GL_POINT_SMOOTH);
  }
  glDisableClientState(GL_VERTEX_ARRAY);
};

void s21::ViewOpenGLScene::SetDefault() {
  state_.setValue("vertices_colorR", 0.0);
  state_.setValue("vertices_colorG", 0.0);
  state_.setValue("vertices_colorB", 1.0);
  state_.setValue("vertices_size", 3);
  state_.setValue("vertices_type", QUAD);

  state_.setValue("lines_colorR", 1.0);
  state_.setValue("lines_colorG", 0.0);
  state_.setValue("lines_colorB", 0.0);
  state_.setValue("lines_size", 3);
  state_.setValue("lines_type", SOLID);

  state_.setValue("projection_colorR", 0.0);
  state_.setValue("projection_colorG", 0.0);
  state_.setValue("projection_colorB", 0.0);
  state_.setValue("projection_type", CENTRAL);
}

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
