#-------------------------------------------------
#
# Project created by QtCreator 2021-01-03T15:38:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = classDesign1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        widget.cpp \
    basicclass.cpp \
    books.cpp \
    videos.cpp \
    pictures.cpp \
    student.cpp \
    admin.cpp \
    login.cpp \
    booklist.cpp \
    additem.cpp \
    videolist.cpp \
    picturelist.cpp

HEADERS += \
        widget.h \
    basicclass.h \
    books.h \
    videos.h \
    pictures.h \
    student.h \
    admin.h \
    login.h \
    booklist.h \
    additem.h \
    videolist.h \
    picturelist.h

FORMS += \
        widget.ui

RESOURCES += \
    icon.qrc \
    data.qrc
