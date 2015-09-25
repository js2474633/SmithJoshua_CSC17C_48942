TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    llvector.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    llvector.h

