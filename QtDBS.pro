QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT+=sql

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DatabaseConnection.cpp \
    MyTableProxy.cpp \
    addabr.cpp \
    addoption.cpp \
    customerform.cpp \
    deviceform.cpp \
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
    tables.cpp

HEADERS += \
    DatabaseConnection.h \
    MyTableProxy.h \
    addabr.h \
    addoption.h \
    customerform.h \
    deviceform.h \
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
    tables.h

FORMS += \
    addabr.ui \
    addoption.ui \
    customerform.ui \
    deviceform.ui \
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
    build/Desktop_Qt_5_15_2_MinGW_64_bit-Debug/debug/JSON/info.json \
    build/Desktop_Qt_5_15_2_MinGW_64_bit-Debug/debug/JSON/items.json \
    build/Desktop_Qt_5_15_2_MinGW_64_bit-Debug/debug/style/Style.qss
