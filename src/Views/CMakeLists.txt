cmake_minimum_required(VERSION 3.5)

project(Views VERSION 0.1 LANGUAGES CXX)

set(CMAKE_PREFIX_PATH "/usr/local/qt;/opt/qt;$ENV{QT_INSTALL_DIR};$ENV{QTDIR};~/Qt/")
set(CMAKE_PREFIX_PATH "/home/superboy/Qt/6.6.2/gcc_64/lib/cmake/Qt6")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
add_definitions(-w)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets OpenGLWidgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets OpenGLWidgets)

set(PROJECT_SOURCES
    main.cc
        view.cc
        view.h
        view.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Views
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        viewopenglscene.h viewopenglscene.cc

        ../Models/model_scene.h
        ../Controllers/controller.cc ../Controllers/controller.h

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Views APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Views SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Views
            ${PROJECT_SOURCES}
        )
    endif()
endif()


target_link_libraries(Views PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(Views PRIVATE Qt${QT_VERSION_MAJOR}::Gui)
target_link_libraries(Views PRIVATE Qt${QT_VERSION_MAJOR}::OpenGLWidgets)
target_link_libraries(Views PRIVATE Qt${QT_VERSION_MAJOR}::Core)

# target_link_libraries(Views PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
# target_link_libraries(Views PRIVATE Qt6::Widgets Qt6::OpenGL Qt6::OpenGLWidgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Views)
endif()
set_target_properties(Views PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Views
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Views)
endif()
