#include "MainWindow.h"

#include <QDesktopServices>
#include <QResource>
#include <QProcess>
#include <QTemporaryFile>
#include <QDir>
#include <QDebug>
#include <QUrl>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

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
    delete ui;
}

