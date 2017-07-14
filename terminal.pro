QT += widgets serialport

TARGET = bvs
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    settingsdialog.cpp \
    console.cpp \
    bvs_wallet.cpp \
    ausfuehrendialog.cpp

HEADERS += \
    mainwindow.h \
    settingsdialog.h \
    console.h \
    bvs_wallet.h \
    ausfuehrendialog.h

FORMS += \
    mainwindow.ui \
    settingsdialog.ui \
    bvs_wallet.ui \
    ausfuehrendialog.ui

RESOURCES += \
    terminal.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/serialport/terminal
INSTALLS += target
