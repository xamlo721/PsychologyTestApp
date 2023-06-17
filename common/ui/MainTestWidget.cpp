#include "MainTestWidget.h"

#include <QDesktopServices>
#include <QResource>
#include <QProcess>
#include <QTemporaryFile>
#include <QDir>

#include "common/ui/test/EnumAvailableTestWidgets.h"


MainTestWidget::MainTestWidget(QWidget *parent) : QWidget(parent),  ui(new Ui::MainTestWidget) {
    ui->setupUi(this);


    QObject::connect(this->ui->mainMenu->ui->TestLiri, &QPushButton::clicked, this, &MainTestWidget::onMainMenuLiriTestButtonClicked);
    QObject::connect(this->ui->mainMenu->ui->TestTorston, &QPushButton::clicked, this, &MainTestWidget::onMainMenuTorsonTestButtonClicked);

    QObject::connect(this->ui->infoLiri->uiInstructionLiri->tothetest, &QPushButton::clicked, this, &MainTestWidget::onInfoLiriTestButtonClicked);
    QObject::connect(this->ui->infoTorson->uiInstructionTorston->tothetest, &QPushButton::clicked, this, &MainTestWidget::onInfoTorsonTestButtonClicked);

    QObject::connect(this->ui->questResult->uiResult->tothemain, &QPushButton::clicked, this, &MainTestWidget::onTestComplete);
    QObject::connect(this->ui->resultTorston->ui->tothemain, &QPushButton::clicked, this, &MainTestWidget::onTestComplete);

    QObject::connect(this->ui->questLiri, &QuestionLiriWidget::signalAborted, this, &MainTestWidget::onTestAborted);
    QObject::connect(this->ui->questTorson, &QuestionTorsonWidget::signalAborted, this, &MainTestWidget::onTestAborted);



}



void MainTestWidget::showResult(TorstonResult result) {
    this->ui->stackedWidget->setCurrentIndex(EnumAvailableTestWidgets::ResultTorston);
    this->ui->resultTorston->showResult(result);
}



void MainTestWidget::onMainMenuLiriTestButtonClicked() {
    emit signalSelectTest(EnumTestType::Liri);
    this->ui->stackedWidget->setCurrentIndex(EnumAvailableTestWidgets::InfoLiri);

}

void MainTestWidget::onMainMenuTorsonTestButtonClicked() {
    emit signalSelectTest(EnumTestType::Torston);
    //TODO:
    this->ui->stackedWidget->setCurrentIndex(EnumAvailableTestWidgets::InfoTorson);

}

void MainTestWidget::onInfoLiriTestButtonClicked() {
    emit signalTestStarted();
    this->ui->stackedWidget->setCurrentIndex(EnumAvailableTestWidgets::QuestLiri);
}

void MainTestWidget::onInfoTorsonTestButtonClicked() {
    emit signalTestStarted();
    this->ui->stackedWidget->setCurrentIndex(EnumAvailableTestWidgets::QuestTorson);

}

void MainTestWidget::onTestAborted() {
    this->ui->stackedWidget->setCurrentIndex(EnumAvailableTestWidgets::MainMenu);
    emit signalTestAborted();
}

void MainTestWidget::onTestComplete() {
    emit signalTestComplete();
    this->ui->stackedWidget->setCurrentIndex(EnumAvailableTestWidgets::MainMenu);
}

void MainTestWidget::onHelpOpened() {

    QFile resourceFile(":/help/PsychologyTest.chm");
    QString tempPath = QDir::tempPath() + "/PsychologyTest.chm";

    if (QFile::exists(tempPath)) {
        if (QFile::remove(tempPath)) {// если файл удален успешно
            qDebug() << "File removed successfully.";
        } else {// если произошла ошибка при удалении
            qDebug() << "Failed to remove the file."; //Я не понимаю почему,но он не удаляет ничего
        }
    }

    if (!resourceFile.copy(tempPath)) {
        qDebug() << "Failed to copy the file to temporary directory.";
        qDebug() << tempPath;
    }

    QDesktopServices::openUrl(QUrl::fromLocalFile(tempPath));//Костыль.

}

void MainTestWidget::keyPressEvent(QKeyEvent *event) {

    if (event->key() == Qt::Key_F1) {
        this->onHelpOpened();
    }

}

MainTestWidget::~MainTestWidget() {
    delete ui;
}
