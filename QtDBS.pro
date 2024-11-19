QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT+=sql
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
# QXlsx code for Application Qt project
QXLSX_PARENTPATH=./         # current QXlsx path is . (. means curret directory)
QXLSX_HEADERPATH=./header/  # current QXlsx header path is ./header/
QXLSX_SOURCEPATH=./source/  # current QXlsx source path is ./source/
include(./QXlsx.pri)
SOURCES += \
    DatabaseConnection.cpp \
    DllHandler.cpp \
    MyTableProxy.cpp \
    addabr.cpp \
    addoption.cpp \
    changedb.cpp \
    customerform.cpp \
    deleteoption.cpp \
    deviceform.cpp \
    edititem.cpp \
    exporttoexcel.cpp \
    hidebelonging.cpp \
    itemhandler.cpp \
    jsonhandler.cpp \
    logger.cpp \
    main.cpp \
    mainwindow.cpp \
    myfunctions.cpp \
    productproxy.cpp \
    productregister.cpp \
    proxyview.cpp \
    searchform.cpp \
    serviceedit.cpp \
    tables.cpp \

HEADERS += \
    DatabaseConnection.h \
    DllHandler.h \
    MyTableProxy.h \
    addabr.h \
    addoption.h \
    changedb.h \
    customerform.h \
    deleteoption.h \
    deviceform.h \
    edititem.h \
    exporttoexcel.h \
    hidebelonging.h \
    itemhandler.h \
    jsonhandler.h \
    logger.h \
    mainwindow.h \
    myfunctions.h \
    productproxy.h \
    productregister.h \
    proxyview.h \
    searchform.h \
    serviceedit.h \
    tables.h \

FORMS += \
    addabr.ui \
    addoption.ui \
    changedb.ui \
    customerform.ui \
    deleteoption.ui \
    deviceform.ui \
    edititem.ui \
    hidebelonging.ui \
    mainwindow.ui \
    productregister.ui \
    searchform.ui \
    serviceedit.ui \
    tables.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    build/Desktop_Qt_5_15_2_MinGW_32_bit-Debug/debug/DBPath \
    build/Desktop_Qt_5_15_2_MinGW_32_bit-Debug/debug/JSON/AdminActive \
    build/Desktop_Qt_5_15_2_MinGW_32_bit-Debug/debug/JSON/info.json \
    build/Desktop_Qt_5_15_2_MinGW_32_bit-Debug/debug/JSON/items.json \
    build/Desktop_Qt_5_15_2_MinGW_32_bit-Debug/debug/JSONPath \
    build/Desktop_Qt_5_15_2_MinGW_32_bit-Debug/debug/style/Style.qss

