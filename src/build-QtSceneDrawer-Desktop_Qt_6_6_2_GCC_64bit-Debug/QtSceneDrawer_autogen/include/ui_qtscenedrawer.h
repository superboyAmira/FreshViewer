/********************************************************************************
** Form generated from reading UI file 'qtscenedrawer.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTSCENEDRAWER_H
#define UI_QTSCENEDRAWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtSceneDrawer
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_file_info;
    QLabel *label_polygons;
    QLabel *label_vertices;
    QLabel *labe_path;
    QPushButton *pushButton_file_path;
    QOpenGLWidget *openGLWidget;
    QMenuBar *menubar;
    QMenu *menu3DViewer;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QtSceneDrawer)
    {
        if (QtSceneDrawer->objectName().isEmpty())
            QtSceneDrawer->setObjectName("QtSceneDrawer");
        QtSceneDrawer->resize(800, 600);
        centralwidget = new QWidget(QtSceneDrawer);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout_file_info = new QGridLayout();
        gridLayout_file_info->setObjectName("gridLayout_file_info");
        label_polygons = new QLabel(centralwidget);
        label_polygons->setObjectName("label_polygons");
        label_polygons->setAlignment(Qt::AlignCenter);

        gridLayout_file_info->addWidget(label_polygons, 1, 1, 1, 1);

        label_vertices = new QLabel(centralwidget);
        label_vertices->setObjectName("label_vertices");
        label_vertices->setAlignment(Qt::AlignCenter);

        gridLayout_file_info->addWidget(label_vertices, 1, 0, 1, 1);

        labe_path = new QLabel(centralwidget);
        labe_path->setObjectName("labe_path");

        gridLayout_file_info->addWidget(labe_path, 0, 0, 1, 2);


        gridLayout->addLayout(gridLayout_file_info, 1, 0, 1, 1);

        pushButton_file_path = new QPushButton(centralwidget);
        pushButton_file_path->setObjectName("pushButton_file_path");

        gridLayout->addWidget(pushButton_file_path, 2, 0, 1, 1);

        openGLWidget = new QOpenGLWidget(centralwidget);
        openGLWidget->setObjectName("openGLWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(openGLWidget->sizePolicy().hasHeightForWidth());
        openGLWidget->setSizePolicy(sizePolicy);

        gridLayout->addWidget(openGLWidget, 0, 0, 1, 1);

        QtSceneDrawer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QtSceneDrawer);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menu3DViewer = new QMenu(menubar);
        menu3DViewer->setObjectName("menu3DViewer");
        QtSceneDrawer->setMenuBar(menubar);
        statusbar = new QStatusBar(QtSceneDrawer);
        statusbar->setObjectName("statusbar");
        QtSceneDrawer->setStatusBar(statusbar);

        menubar->addAction(menu3DViewer->menuAction());

        retranslateUi(QtSceneDrawer);

        QMetaObject::connectSlotsByName(QtSceneDrawer);
    } // setupUi

    void retranslateUi(QMainWindow *QtSceneDrawer)
    {
        QtSceneDrawer->setWindowTitle(QCoreApplication::translate("QtSceneDrawer", "QtSceneDrawer", nullptr));
        label_polygons->setText(QCoreApplication::translate("QtSceneDrawer", "Count of polygons", nullptr));
        label_vertices->setText(QCoreApplication::translate("QtSceneDrawer", "Count of vertices", nullptr));
        labe_path->setText(QCoreApplication::translate("QtSceneDrawer", "Opened file name", nullptr));
        pushButton_file_path->setText(QCoreApplication::translate("QtSceneDrawer", "Open file", nullptr));
        menu3DViewer->setTitle(QCoreApplication::translate("QtSceneDrawer", "3DViewer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtSceneDrawer: public Ui_QtSceneDrawer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTSCENEDRAWER_H
