TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt opengl core gui
isEqual(QT_MAJOR_VERSION, 5) {
        cache()
        DEFINES +=QT5BUILD
}

SOURCES += main.cpp

HEADERS +=

LIBS += -lGL -lGLU -lGLEW -lSDL2

