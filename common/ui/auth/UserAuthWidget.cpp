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

    this->ui->auth_pushButton->setDisabled(true);
    this->ui->edit_pushButton->setDisabled(true);
    this->ui->remove_pushButton->setDisabled(true);

}


void UserAuthWidget::showUserAccounts(QList <QString> accounts) {

    for (QString account : accounts) {
        this->onNewUserAccont(account);//Говнокод
    }
}

void UserAuthWidget::onAuthButtonPressed() {
    //TODO: Выбрать аккаунт, по которому кликали и кинуть сигнал вверху
    emit signalAuthUser(this->selectedAccount);
}

void UserAuthWidget::onAddButtonPressed() {
    //TODO: Вызвать диалоговое окно ввода имени
    UserDialog * nameDialog = new UserDialog();
    nameDialog->show();
    QObject::connect(nameDialog, &UserDialog::signalOnAnswered, this, &UserAuthWidget::onNewUserAccont);

}

void UserAuthWidget::onEditButtonPressed() {
    //TODO: Вызвать диалоговое окно ввода имени
    //TODO: Вызвать диалоговое окно ввода имени
    UserDialog * nameDialog = new UserDialog();
    nameDialog->show();
    QObject::connect(nameDialog, &UserDialog::signalOnAnswered, this, &UserAuthWidget::onEditUserAccont);//TODO: Не туда коннектим
}
void UserAuthWidget::onEditUserAccont(QString account) {

    UserAccountPutton * button = this->accounts.take(this->selectedAccount);
    button->setText(account);
    this->selectedAccount = account;
    this->accounts.insert(account, button);
}


void UserAuthWidget::onRemoveButtonPressed() {
    this->clearAccountsList();
    this->accounts.take(this->selectedAccount);
    QList<QString> accountsNames = this->accounts.keys();
    this->accounts.clear();
    this->selectedAccount = "";
    this->onUnselectAccount();
    this->showUserAccounts(accountsNames);
}

void UserAuthWidget::onCancelButtonPressed() {
    emit signalCancel();
}

void UserAuthWidget::onUserAccountClicked(QString account) {
    qDebug() << account;

    this->selectedAccount = account;

    for(UserAccountPutton * b : this->accounts.values()) {
        b->setChecked(false);
    }

    UserAccountPutton * selectedAccount = accounts.value(account);
    selectedAccount->setChecked(true);

    this->onSelectAccount();

}

void UserAuthWidget::onNewUserAccont(QString account) {
    qDebug() << account;
    if (account.isEmpty()) {
        //TODO: сделать что-иньбудь
        return;
    }

    UserAccountPutton * button = new UserAccountPutton(account);
    this->ui->scrollArea->layout()->addWidget(button);
    accounts.insert(account, button);
    QObject::connect(button, &UserAccountPutton::signalSelected, this, &UserAuthWidget::onUserAccountClicked);//TODO: Не туда коннектим
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

void UserAuthWidget::onSelectAccount() {
    this->ui->auth_pushButton->setDisabled(false);
    this->ui->edit_pushButton->setDisabled(false);
    this->ui->remove_pushButton->setDisabled(false);
}

void UserAuthWidget::onUnselectAccount() {
    this->ui->auth_pushButton->setDisabled(true);
    this->ui->edit_pushButton->setDisabled(true);
    this->ui->remove_pushButton->setDisabled(true);
}

UserAuthWidget::~UserAuthWidget() {
    delete ui;
}
