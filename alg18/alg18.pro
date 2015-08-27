TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    treap.cpp \
    bstree.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    treap.h \
    bstree.h

