QT += core
QT -= gui

TARGET = IC-Matheus
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Edge.cpp \
    Vertex.cpp \
    VertexCaracAltura.cpp \
    VertexCaracLargura.cpp \
    VertexCaracPeso.cpp \
    VertexPerson.cpp

INCLUDEPATH += C:\Users\Matheus\Desktop\Programacaoeetc\boost_1_59_0
LIBS += -LC:\Users\Matheus\Desktop\Programacaoeetc\boost_1_59_0/stage/lib/
LIBS += -llibboost_filesystem-vc150-mt-gd-1_59

HEADERS += \
    Edge.h \
    Vertex.h \
    VertexCaracAltura.h \
    VertexCaracLargura.h \
    VertexCaracPeso.h \
    VertexPerson.h
