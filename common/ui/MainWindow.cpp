#include "MainWindow.h"

#include <QDesktopServices>
#include <QResource>
#include <QProcess>
#include <QTemporaryFile>
#include <QDir>
#include <QDebug>
#include <QUrl>
#include <QKeyEvent>

#include "common/ui/EnumUIMode.h"
#include "common/ui/test/EnumAvailableTestWidgets.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->ui->stackedWidget->setCurrentIndex(EnumUIMode::Auth);
    QObject::connect(this->ui->authWidget, &MainAuthWidget::signalReadyForTest, this, &MainWindow::onTestReady);
    QObject::connect(this->ui->testWidget, &MainTestWidget::signalTestComplete, this, &MainWindow::onTestComplete);
    QObject::connect(this->ui->testWidget, &MainTestWidget::signalTestStarted, this, &MainWindow::onTestStarted);

    QObject::connect(this->ui->authWidget, &MainAuthWidget::signalAuthUser, this, &MainWindow::onAuthUser);
    QObject::connect(this->ui->authWidget, &MainAuthWidget::signalAddUser, this, &MainWindow::onAddUser);
    QObject::connect(this->ui->authWidget, &MainAuthWidget::signalEditUser, this, &MainWindow::onEditUser);
    QObject::connect(this->ui->authWidget, &MainAuthWidget::signalDeleteUser, this, &MainWindow::onDeleteUser);

}

void MainWindow::onTestComplete() {
    this->ui->stackedWidget->setCurrentIndex(EnumUIMode::Auth);
}

void MainWindow::onTestReady() {
    this->ui->stackedWidget->setCurrentIndex(EnumUIMode::Test);
}
void MainWindow::displayLiriResult(LiriResult result) {
    this->ui->testWidget->ui->stackedWidget->setCurrentIndex(EnumAvailableTestWidgets::ResultLiri);//Костыль
    this->ui->testWidget->ui->questResult->displayRadar(result.st1, result.st2,result.st3,result.st4,result.st5,result.st6,result.st7,result.st8);

}
void MainWindow::displayTorstonResult() {

}

void MainWindow::onAuthUser(UserAccount user) {
    emit signalAuthUser(user);
}

void MainWindow::onAddUser(QString user) {
    emit signalAddUser(user);

}

void MainWindow::onEditUser(UserAccount user) {
    emit signalEditUser(user);

}

void MainWindow::onDeleteUser(UserAccount user) {
    emit signalDeleteUser(user);

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

void MainWindow::onTestStarted() {
    emit signalTestStarted();
}


MainWindow::~MainWindow() {
    delete ui;
}

