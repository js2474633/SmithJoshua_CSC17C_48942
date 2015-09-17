TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    triangularmatrix.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    triangularmatrix.h

