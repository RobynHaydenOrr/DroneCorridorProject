QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminlogin.cpp \
    approvenew.cpp \
    listexisting.cpp \
    main.cpp \
    mainmenu.cpp \
    mapexisting.cpp \
    registernew.cpp

HEADERS += \
    adminlogin.h \
    approvenew.h \
    listexisting.h \
    mainmenu.h \
    mapexisting.h \
    registernew.h

FORMS += \
    adminlogin.ui \
    approvenew.ui \
    listexisting.ui \
    mainmenu.ui \
    mapexisting.ui \
    registernew.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
