#include "MainWindow.h"
#include "common/ui/EnumAvailableWidgets.h"
#include <QDesktopServices>

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
    qDebug() << "Open help";
    // Определите путь к файлу справки
    QString helpPath = "help.html";
    QString fullPath = "C:/workspace/PsychologyTestApp/Test2.chm";

    // Откройте файл справки в браузере
    QDesktopServices::openUrl(QUrl::fromLocalFile(fullPath));

}


void MainWindow::keyPressEvent(QKeyEvent *event) {
    qDebug() << "KeyPressed!";

    if (event->key() == Qt::Key_F1) {
        //TODO: открыть справку. Кто-то знает как она выглядит??
        qDebug() << "F1 pressed!";
        this->onHelpOpened();

    }

}


bool MainWindow::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::KeyPress) {
        auto *keyEvent = static_cast<QKeyEvent *>(event);
        int key = keyEvent->key();
        // Return true to reject the key-presses
        if  (key == Qt::Key_Left || key == Qt::Key_Right || key == Qt::Key_Up || key == Qt::Key_Down)
        {
            //process event here somehow, or instruct your class to do it later
            return true; //filter the event
        }
    } else {
        // standard event processing
        return QMainWindow::eventFilter(obj, event);
    }
}

MainWindow::~MainWindow() {
    delete ui_window;
}

