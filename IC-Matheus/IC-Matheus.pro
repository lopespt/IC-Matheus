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
    VertexPerson.cpp \
    pprob.cpp


if(linux-g++*|macx-g++*):CONFIG(debug, debug|release) {
    INCLUDEPATH += /opt/local/include/
    LIBS += -L/opt/local/lib/
    LIBS += -lboost_filesystem-mt
} else {
    INCLUDEPATH += C:\Users\Matheus\Desktop\Programacaoeetc\boost_1_59_0
    LIBS += -LC:\Users\Matheus\Desktop\Programacaoeetc\boost_1_59_0/stage/lib/
    LIBS += -llibboost_filesystem-vc150-mt-gd-1_59
}


HEADERS += \
    Edge.h \
    Vertex.h \
    VertexCaracAltura.h \
    VertexCaracLargura.h \
    VertexCaracPeso.h \
    VertexPerson.h \
    pprob.h
