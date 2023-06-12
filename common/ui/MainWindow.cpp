#include "MainWindow.h"
#include "common/ui/EnumAvailableWidgets.h"
#include <QDesktopServices>
#include <QResource>
#include <QProcess>
#include <QTemporaryFile>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui_window(new Ui::MainWindow) {
    ui_window->setupUi(this);

    QObject::connect(this->ui_window->mainMenu->ui->TestLiri, &QPushButton::clicked, this, &MainWindow::onMainMenuLiriTestButtonClicked);
    QObject::connect(this->ui_window->mainMenu->ui->TestTorston, &QPushButton::clicked, this, &MainWindow::onMainMenuTorsonTestButtonClicked);

    QObject::connect(this->ui_window->infoLiri->uiInstructionLiri->tothetest, &QPushButton::clicked, this, &MainWindow::onInfoLiriTestButtonClicked);
    QObject::connect(this->ui_window->infoTorson->uiInstructionTorston->tothetest, &QPushButton::clicked, this, &MainWindow::onInfoTorsonTestButtonClicked);

    QObject::connect(this->ui_window->questResult->uiResult->tothemain, &QPushButton::clicked, this, &MainWindow::onTestComplete);
    QObject::connect(this->ui_window->resultTorston->ui->tothemain, &QPushButton::clicked, this, &MainWindow::onTestComplete);

    QObject::connect(this->ui_window->questLiri, &QuestionLiriWidget::signalAborted, this, &MainWindow::onTestAborted);
    QObject::connect(this->ui_window->questTorson, &QuestionTorsonWidget::signalAborted, this, &MainWindow::onTestAborted);


}

void MainWindow::showResult(EnumTorsonResult result) {
    this->ui_window->stackedWidget->setCurrentIndex(EnumAvailableWidgets::ResultTorston);
    this->ui_window->resultTorston->showResult(result);
}


void MainWindow::onMainMenuLiriTestButtonClicked() {
    emit signalSelectTest(EnumTestType::Liri);
    this->ui_window->stackedWidget->setCurrentIndex(EnumAvailableWidgets::InfoLiri);

}

void MainWindow::onMainMenuTorsonTestButtonClicked() {
    emit signalSelectTest(EnumTestType::Torston);
    //TODO:
    this->ui_window->stackedWidget->setCurrentIndex(EnumAvailableWidgets::InfoTorson);

}

void MainWindow::onInfoLiriTestButtonClicked() {
    emit signalTestStarted(EnumTestType::Liri);
    this->ui_window->stackedWidget->setCurrentIndex(EnumAvailableWidgets::QuestLiri);
}

void MainWindow::onInfoTorsonTestButtonClicked() {
    emit signalTestStarted(EnumTestType::Torston);
    this->ui_window->stackedWidget->setCurrentIndex(EnumAvailableWidgets::QuestTorson);

}

void MainWindow::onTestAborted() {
    this->ui_window->stackedWidget->setCurrentIndex(EnumAvailableWidgets::MainMenu);
    emit signalTestAborted();
}


void MainWindow::onTestComplete() {
    emit signalTestComplete();
    this->ui_window->stackedWidget->setCurrentIndex(EnumAvailableWidgets::MainMenu);
}

void MainWindow::onHelpOpened() {

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


void MainWindow::keyPressEvent(QKeyEvent *event) {

    if (event->key() == Qt::Key_F1) {
        this->onHelpOpened();
    }

}

MainWindow::~MainWindow() {
    delete ui_window;
}

