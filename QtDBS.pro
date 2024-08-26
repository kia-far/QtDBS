QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT+=sql

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DatabaseConnection.cpp \
    addoption.cpp \
    customerform.cpp \
    deviceedit.cpp \
    deviceform.cpp \
    edittable.cpp \
    itemabstract.cpp \
    itemhandler.cpp \
    jsonhandler.cpp \
    main.cpp \
    mainwindow.cpp \
    myfunctions.cpp \
    productedit.cpp \
    productproxy.cpp \
    productregister.cpp \
    proxyview.cpp \
    requestform.cpp \
    searchform.cpp \
    serviceedit.cpp \
    singleton.cpp \
    tables.cpp

HEADERS += \
    DatabaseConnection.h \
    addoption.h \
    customerform.h \
    deviceedit.h \
    deviceform.h \
    edittable.h \
    itemabstract.h \
    itemhandler.h \
    jsonhandler.h \
    mainwindow.h \
    myfunctions.h \
    productedit.h \
    productproxy.h \
    productregister.h \
    proxyview.h \
    requestform.h \
    searchform.h \
    serviceedit.h \
    singleton.h \
    tables.h

FORMS += \
    addoption.ui \
    customerform.ui \
    deviceedit.ui \
    deviceform.ui \
    edittable.ui \
    mainwindow.ui \
    productregister.ui \
    requestform.ui \
    searchform.ui \
    serviceedit.ui \
    tables.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../build-QtDBS-Desktop_Qt_5_12_12_MinGW_64_bit-Debug/history/info.json \
    ../build-QtDBS-Desktop_Qt_5_12_12_MinGW_64_bit-Debug/history/items.json \
    ../build-QtDBS-Desktop_Qt_5_12_12_MinGW_64_bit-Debug/style/Style.qss
