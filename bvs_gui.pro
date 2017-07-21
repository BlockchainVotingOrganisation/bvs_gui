QT += widgets

TARGET = bvs
TEMPLATE = app

SOURCES += \
    main.cpp \
    bvs_wallet.cpp \
    ausfuehrendialog.cpp \
    projekteauswahl.cpp \
    Classes/Domain/Model/project.cpp \
    Classes/Domain/projectRepository.cpp \
    Classes/Controller/projectcontroller.cpp \
    settingsdialog.cpp

HEADERS += \
    bvs_wallet.h \
    ausfuehrendialog.h \
    projekteauswahl.h \
    Classes/Domain/Model/project.h \
    Classes/Domain/projectRepository.h \
    Classes/Controller/projectController.h \
    settingsdialog.h

FORMS += \
    bvs_wallet.ui \
    ausfuehrendialog.ui \
    projekteauswahl.ui \
    settingsdialog.ui

RESOURCES += \
    terminal.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/serialport/terminal
INSTALLS += target

DISTFILES += \
    README.md
