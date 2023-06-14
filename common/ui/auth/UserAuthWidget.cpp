#include "UserAuthWidget.h"
#include "common/ui/auth/UserDialog.h"
#include <QDebug>

UserAuthWidget::UserAuthWidget(QWidget *parent) : QWidget(parent), ui(new Ui::UserAuthWidget) {
    ui->setupUi(this);
    QObject::connect(this->ui->auth_pushButton, &QPushButton::clicked, this, &UserAuthWidget::onAuthButtonPressed);
    QObject::connect(this->ui->add_pushButton, &QPushButton::clicked, this, &UserAuthWidget::onAddButtonPressed);
    QObject::connect(this->ui->edit_pushButton, &QPushButton::clicked, this, &UserAuthWidget::onEditButtonPressed);
    QObject::connect(this->ui->remove_pushButton, &QPushButton::clicked, this, &UserAuthWidget::onRemoveButtonPressed);
    QObject::connect(this->ui->cancel_pushButton, &QPushButton::clicked, this, &UserAuthWidget::onCancelButtonPressed);

    ui->scrollArea->setLayout(new QVBoxLayout());
    ui->scrollArea->layout()->setAlignment(Qt::AlignTop);

}


void UserAuthWidget::showUserAccounts() {//TODO: Добавить лист

}

void UserAuthWidget::onAuthButtonPressed() {
    //TODO: Выбрать аккаунт, по которому кликали и кинуть сигнал вверху
    emit signalAuthUser();
}

void UserAuthWidget::onAddButtonPressed() {
    //TODO: Вызвать диалоговое окно ввода имени
    UserDialog * nameDialog = new UserDialog();
    nameDialog->show();
    QObject::connect(nameDialog, &UserDialog::signalOnAnswered, this, &UserAuthWidget::onNewUserAccont);

}

void UserAuthWidget::onEditButtonPressed() {
    //TODO: Вызвать диалоговое окно ввода имени
}

void UserAuthWidget::onRemoveButtonPressed() {
    //TODO: Вызвать диалоговое окно подтверждения
}

void UserAuthWidget::onCancelButtonPressed() {
    emit signalCancel();
}

void UserAuthWidget::onUserAccountClicked() {

}

void UserAuthWidget::onNewUserAccont(QString account) {
    qDebug() << account;
    if (account.isEmpty()) {
        //TODO: сделать что-иньбудь
        return;
    }

    QPushButton * button = new QPushButton();
    button->setText(account);
    button->setCheckable(true);
    this->ui->scrollArea->layout()->addWidget(button);
}

QPushButton * UserAuthWidget::findPressedAccount() {

}

void UserAuthWidget::clearAccountsList() {
    QWidget * m_view = this->ui->scrollArea;
    if ( m_view->layout() != NULL ) {
        QLayoutItem* item;
        while ( ( item = m_view->layout()->takeAt( 0 ) ) != NULL ) {
            delete item->widget();
            delete item;
        }
        //delete m_view->layout();
    }
}

UserAuthWidget::~UserAuthWidget() {
    delete ui;
}
