#ifndef VIEWOPENGLSCENE_H
#define VIEWOPENGLSCENE_H

#include <QMouseEvent>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QSettings>
#include <QWidget>

namespace s21 {

enum ProjectrionType { CENTRAL, PARALLEL };

enum VerticesType { QUAD, ROUNDED, NONE };

enum LinesType { SOLID, DOTTED };

class ViewOpenGLScene : public QOpenGLWidget {
  Q_OBJECT
 public:
  explicit ViewOpenGLScene(QWidget *parent = nullptr);

  void LoadScene();

  void SetVertices(std::vector<double> &);

  void SetLines(std::vector<int> &);

  QSettings *GetState();

 protected:
  void initializeGL() override;
  void resizeGL(int width, int height) override;
  void paintGL() override;

 private:
  std::vector<double> vertices_;
  std::vector<int> lines_;

  /*
   * Mouse Moving Implementation
   */
  QPoint mPos;
  double xRot, yRot, zoom;
  void mouseMoveEvent(QMouseEvent *) override;
  void mousePressEvent(QMouseEvent *) override;
  void wheelEvent(QWheelEvent *) override;

  /*
   * Settings
   */
  QSettings state_;
  void SetDefault();
};

}  // namespace s21

#endif  // VIEWOPENGLSCENE_H
