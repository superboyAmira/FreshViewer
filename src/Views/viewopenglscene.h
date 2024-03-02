#ifndef VIEWOPENGLSCENE_H
#define VIEWOPENGLSCENE_H

#include <QWidget>
#include <QMouseEvent>


#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLContext>


namespace s21 {
class ViewOpenGLScene : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit ViewOpenGLScene(QWidget *parent = nullptr);

    void LoadScene();

    void SetVertices(std::vector<double>&);
    void SetLines(std::vector<int>&);
signals:

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
};
}

#endif // VIEWOPENGLSCENE_H
