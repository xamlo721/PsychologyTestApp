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

    QPixmap bkgnd(":/pictures/back.png");
    bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
    QPalette p = palette(); //copy current, not create new
    p.setBrush(QPalette::Background, bkgnd);

    this->setPalette(p);


    QObject::connect(this->ui->authWidget, &MainAuthWidget::signalReadyForTest, this, &MainWindow::onTestReady);
    QObject::connect(this->ui->testWidget, &MainTestWidget::signalTestComplete, this, &MainWindow::onTestComplete);
    QObject::connect(this->ui->testWidget, &MainTestWidget::signalSelectTest, this, &MainWindow::signalSelectTest);
    QObject::connect(this->ui->testWidget, &MainTestWidget::signalTestStarted, this, &MainWindow::onTestStarted);
    QObject::connect(this->ui->testWidget, &MainTestWidget::signalTestComplete, this, &MainWindow::signalTestComplete);
    QObject::connect(this->ui->testWidget, &MainTestWidget::signalTestAborted, this, &MainWindow::signalTestAborted);


    QObject::connect(this->ui->testWidget->ui->questLiri, &QuestionLiriWidget::signalAnswerd, this, &MainWindow::signalLiriAnswered);
    QObject::connect(this->ui->testWidget->ui->questTorson, &QuestionTorsonWidget::signalAnswered, this, &MainWindow::signalTorstonAnswered);


    QObject::connect(this->ui->authWidget, &MainAuthWidget::signalAuthUser, this, &MainWindow::onAuthUser);
    QObject::connect(this->ui->authWidget, &MainAuthWidget::signalAddUser, this, &MainWindow::onAddUser);
    QObject::connect(this->ui->authWidget, &MainAuthWidget::signalEditUser, this, &MainWindow::onEditUser);
    QObject::connect(this->ui->authWidget, &MainAuthWidget::signalDeleteUser, this, &MainWindow::onDeleteUser);
    QObject::connect(this->ui->authWidget, &MainAuthWidget::signalDeleteLiriResult, this, &MainWindow::onDeleteLiriResult);
    QObject::connect(this->ui->authWidget, &MainAuthWidget::signalDeleteTorstonResult, this, &MainWindow::onDeleteTorstonResult);

    QObject::connect(this->ui->authWidget, &MainAuthWidget::signalWindowClose, this, &MainWindow::onCloseWindow);

}

void MainWindow::resizeEvent(QResizeEvent *evt) {
    QPixmap bkgnd(":/pictures/back.png");
    bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
    QPalette p = palette(); //copy current, not create new
    p.setBrush(QPalette::Background, bkgnd);
    this->setPalette(p);

    QMainWindow::resizeEvent(evt); //call base implementation
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
void MainWindow::displayTorstonResult(TorstonResult result) {
    this->ui->testWidget->showResult(result);
}

void MainWindow::updateProgressBar(float completePercent) {
    this->ui->testWidget->ui->questLiri->uiQuestionsLiri->progressBar->setValue(completePercent * 100);
    this->ui->testWidget->ui->questTorson->uiQuestionsTorston->progressBar->setValue(completePercent * 100);
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

void MainWindow::onDeleteLiriResult(UserAccount account, LiriResult result) {
    emit signalDeleteLiriResult(account, result);

}
void MainWindow::onDeleteTorstonResult(UserAccount account, TorstonResult result) {
    emit signalDeleteTorstonResult(account, result);
}

void MainWindow::onCloseWindow() {
    this->close();
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

void MainWindow::syncUserList(QList<UserAccount> users) {
    this->ui->authWidget->syncUserList(users);
}

void MainWindow::syncResultsList(QMap <UserAccount, QPair<QList<LiriResult>, QList<TorstonResult>>> results) {
    this->ui->authWidget->syncResultsList(results);
}

void MainWindow::syncProtocols(QMap <UserAccount, QPair<QList<AnswerProtocol>, QList<AnswerProtocol>>> protocols) {
    this->ui->authWidget->syncProtocols(protocols);
}


void MainWindow::changeLiriQuestion(Question q) {
    this->ui->testWidget->ui->questLiri->uiQuestionsLiri->label_question->setText(q.getText());

}

void MainWindow::changeTorstonQuestion(Question q) {
    this->ui->testWidget->ui->questTorson->uiQuestionsTorston->label_question->setText(q.getText());

    if (q.hasPicture()) {

        QString stylesheet = "QWidget#widget_picture {"
                             "	background-image: url(:" + q.getPicturePath() +");\n"
                             "}";
         this->ui->testWidget->ui->questTorson->uiQuestionsTorston->widget_picture->setStyleSheet(stylesheet);
    }
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

