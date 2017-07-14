QT += widgets

TARGET = bvs
TEMPLATE = app

SOURCES += \
    main.cpp \
    bvs_wallet.cpp \
    ausfuehrendialog.cpp \
    projekteauswahl.cpp

HEADERS += \
    bvs_wallet.h \
    ausfuehrendialog.h \
    projekteauswahl.h

FORMS += \
    bvs_wallet.ui \
    ausfuehrendialog.ui \
    projekteauswahl.ui

RESOURCES += \
    terminal.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/serialport/terminal
INSTALLS += target
