QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c99


SOURCES += \
    ./action/action_dot.c \
    ./action/action_points_links.c \
    ./action/action.c \
    ./graph/draw.cpp \
    ./graph/select_action.cpp \
    ./action/errors.c \
    ./graph/main.cpp \
    ./graph/mainwindow.cpp \
    ./action/dot.c \
    ./action/points_links.c \
    ./action/figure.c \


HEADERS += \
    ./action/action_dot.h \
    ./action/action_points_links.h\
    ./action/action.h \
    ./action/dot.h \
    ./action/points_links.h \
    ./action/figure.h \
    ./graph/draw.h \
    ./graph/select_action.h \
    ./action/errors.h \
    ./graph/mainwindow.h \

FORMS += \
    ./graph/mainwindow.ui

TRANSLATIONS += \
    lab_01_en_GB.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
