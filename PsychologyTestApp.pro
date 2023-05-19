QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    common/InitModule.cpp \
    common/controller/UIController.cpp \
    common/items/AbstractTextElement.cpp \
    common/items/Answer.cpp \
    common/items/TestInstruction.cpp \
    common/logic/ApplicationLogic.cpp \
    common/logic/Database.cpp \
    common/items/Question.cpp \
    common/logic/SQLHelper.cpp \
    common/logic/Settings.cpp \
    common/items/Test.cpp \
    common/items/TestResult.cpp \
    common/items/TestSection.cpp \
    common/logic/XMLHelper.cpp \
    main.cpp \
    common/ui/MainWindow.cpp

HEADERS += \
    api/ITextElement.h \
    common/InitModule.h \
    common/controller/UIController.h \
    common/items/AbstractTextElement.h \
    common/items/Answer.h \
    common/items/TestInstruction.h \
    common/logic/ApplicationLogic.h \
    common/logic/Database.h \
    common/items/EnumDatabaseType.h \
    common/items/EnumTestType.h \
    common/items/Question.h \
    common/logic/SQLHelper.h \
    common/logic/Settings.h \
    common/items/Test.h \
    common/items/TestResult.h \
    common/items/TestSection.h \
    common/logic/XMLHelper.h \
    common/ui/MainWindow.h

FORMS += \
    ui/Instructions.ui \
    ui/MainWindow.ui \
    ui/Questions.ui \
    ui/Result.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
