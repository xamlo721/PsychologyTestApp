QT       += core gui xml charts

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
    common/ui/MainAuthWidget.cpp \
    common/ui/auth/PsychoResultWidget.cpp \
    common/ui/auth/UserDialog.cpp \
    common/ui/auth/UserResultLiriWidget.cpp \
    common/ui/auth/UserResultTorstonWidget.cpp \
    common/ui/test/InstructionLiriWidget.cpp \
    common/ui/test/InstrutionTorsonWidget.cpp \
    common/ui/test/QuestionLiriWidget.cpp \
    common/ui/test/QuestionTorsonWidget.cpp \
    common/ui/test/ResultWidget.cpp \
    common/ui/test/TestMenuWidget.cpp \
    common/ui/test/qradar.cpp \
    common/utils/XmlUtils.cpp \
    main.cpp \
    common/ui/MainWindow.cpp \
    common/ui/test/ResultTorson.cpp \
    common/ui/MainTestWidget.cpp \
    common/ui/auth/UserAuthWidget.cpp \
    common/ui/auth/WelcomeAuthWidget.cpp \
    common/ui/auth/UserAccountPutton.cpp

RC_FILE     = resources.rc

HEADERS += \
    api/ITextElement.h \
    common/InitModule.h \
    common/controller/UIController.h \
    common/items/AbstractTextElement.h \
    common/items/Answer.h \
    common/items/EnumTorsonResult.h \
    common/items/LiriResult.h \
    common/items/TestInstruction.h \
    common/items/TorstonResult.h \
    common/items/UserAccount.h \
    common/logic/ApplicationLogic.h \
    common/logic/Database.h \
    common/items/EnumDatabaseType.h \
    common/items/EnumTestType.h \
    common/items/Question.h \
    common/logic/LogicConstants.h \
    common/logic/SQLHelper.h \
    common/logic/Settings.h \
    common/items/Test.h \
    common/items/TestResult.h \
    common/items/TestSection.h \
    common/logic/XMLHelper.h \
    common/ui/EnumUIMode.h \
    common/ui/MainAuthWidget.h \
    common/ui/auth/EnumAvailableAuthWidgets.h \
    common/ui/auth/PsychoResultWidget.h \
    common/ui/auth/UserDialog.h \
    common/ui/auth/UserResultLiriWidget.h \
    common/ui/auth/UserResultTorstonWidget.h \
    common/ui/test/EnumAvailableTestWidgets.h \
    common/ui/test/InstructionLiriWidget.h \
    common/ui/test/InstrutionTorsonWidget.h \
    common/ui/MainWindow.h \
    common/ui/test/QuestionLiriWidget.h \
    common/ui/test/QuestionTorsonWidget.h \
    common/ui/test/ResultWidget.h \
    common/ui/test/TestMenuWidget.h \
    common/ui/test/qradar.h \
    common/utils/XmlUtils.h \
    common/ui/test/ResultTorson.h \
    common/ui/MainTestWidget.h \
    common/ui/auth/UserAuthWidget.h \
    common/ui/auth/WelcomeAuthWidget.h \
    common/ui/auth/UserAccountPutton.h

FORMS += \
    ui/auth/UserDialog.ui \
    ui/auth/UserAccountPutton.ui \
    ui/auth/UserResultLiriWidget.ui \
    ui/auth/UserResultTorstonWidget.ui \
    ui/auth/PsychoResultWidget.ui \
    ui/MainWindow.ui \
    ui/MainAuthWidget.ui \
    ui/MainTestWidget.ui \
    ui/auth/UserAuthWidget.ui \
    ui/auth/WelcomeAuthWidget.ui \
    ui/test/InstructionLiri.ui \
    ui/test/InstructionTorston.ui \
    ui/test/QuestionsLiri.ui \
    ui/test/QuestionsTorston.ui \
    ui/test/Result.ui \
    ui/test/ResultTorson.ui \
    ui/test/TestMenuWidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target docs

DISTFILES += \
    Database.xml \
    pictures/back.png \
    pictures/face.png \
    tests/Torston/images/FIG1.bmp \
    tests/Torston/images/FIG10.bmp \
    tests/Torston/images/FIG11.bmp \
    tests/Torston/images/FIG12.bmp \
    tests/Torston/images/FIG13.bmp \
    tests/Torston/images/FIG14.bmp \
    tests/Torston/images/FIG15.bmp \
    tests/Torston/images/FIG16.bmp \
    tests/Torston/images/FIG17.bmp \
    tests/Torston/images/FIG18.bmp \
    tests/Torston/images/FIG19.bmp \
    tests/Torston/images/FIG2.bmp \
    tests/Torston/images/FIG20.bmp \
    tests/Torston/images/FIG21.bmp \
    tests/Torston/images/FIG22.bmp \
    tests/Torston/images/FIG23.bmp \
    tests/Torston/images/FIG24.bmp \
    tests/Torston/images/FIG25.bmp \
    tests/Torston/images/FIG26.bmp \
    tests/Torston/images/FIG27.bmp \
    tests/Torston/images/FIG28.bmp \
    tests/Torston/images/FIG29.bmp \
    tests/Torston/images/FIG3.bmp \
    tests/Torston/images/FIG30.bmp \
    tests/Torston/images/FIG31.bmp \
    tests/Torston/images/FIG32.bmp \
    tests/Torston/images/FIG33.bmp \
    tests/Torston/images/FIG34.bmp \
    tests/Torston/images/FIG35.bmp \
    tests/Torston/images/FIG36.bmp \
    tests/Torston/images/FIG37.bmp \
    tests/Torston/images/FIG38.bmp \
    tests/Torston/images/FIG39.bmp \
    tests/Torston/images/FIG4.bmp \
    tests/Torston/images/FIG40.bmp \
    tests/Torston/images/FIG41.bmp \
    tests/Torston/images/FIG42.bmp \
    tests/Torston/images/FIG43.bmp \
    tests/Torston/images/FIG44.bmp \
    tests/Torston/images/FIG45.bmp \
    tests/Torston/images/FIG46.bmp \
    tests/Torston/images/FIG47.bmp \
    tests/Torston/images/FIG48.bmp \
    tests/Torston/images/FIG5.bmp \
    tests/Torston/images/FIG6.bmp \
    tests/Torston/images/FIG7.bmp \
    tests/Torston/images/FIG8.bmp \
    tests/Torston/images/FIG9.bmp \
    tests/Torston/images/Fig0.bmp \
    tests/Torston/images/face.png

RESOURCES += \
    ui/aaa.qrc
