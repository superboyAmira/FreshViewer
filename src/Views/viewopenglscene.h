#ifndef VIEWOPENGLSCENE_H
#define VIEWOPENGLSCENE_H

#include <QWidget>
#include <QMouseEvent>
#include <QSettings>

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLContext>

namespace s21 {

enum  ProjectrionType { CENTRAL, PARALLEL };

enum VerticesType { QUAD, ROUNDED, NONE };

enum LinesType { SOLID, DOTTED };

class ViewOpenGLScene : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit ViewOpenGLScene(QWidget *parent = nullptr);

    void LoadScene();

    void SetVertices(std::vector<double>&);

    void SetLines(std::vector<int>&);

    QSettings* GetState();

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

}

#endif // VIEWOPENGLSCENE_H
