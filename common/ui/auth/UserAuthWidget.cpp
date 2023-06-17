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
    this->hasSelectedAccount = false;
}

void UserAuthWidget::changeAccountName(UserAccount account) {
    if (!this->accounts.contains(account)) {
        //TODO: Ваай, зайки, так у нас программа с багами
        return;
    }
    UserAccountPutton * button = this->accounts.take(this->selectedAccount);
    this->selectedAccount = account;
    this->accounts.insert(account, button);
}

void UserAuthWidget::displayNewAccount(UserAccount account) {

    if (accounts.contains(account)) {
        //TODO: сделать что-иньбудь
        return;
    }

    UserAccountPutton * button = new UserAccountPutton(account);
    this->ui->scrollArea->layout()->addWidget(button);
    accounts.insert(account, button);
    QObject::connect(button, &UserAccountPutton::signalSelected, this, &UserAuthWidget::onUserAccountClicked);

}

void UserAuthWidget::displayUserAccounts(QList <UserAccount> accounts) {
    this->clearAccountsListWidgets();
    this->accounts.clear();

    for (UserAccount account : accounts) {
        this->displayNewAccount(account);
    }
    this->onUnselectAccount();

}

void UserAuthWidget::removeDisplayedAccount(UserAccount account) {
    this->accounts.remove(account);
    QList<UserAccount> accountsNames = this->accounts.keys();
    this->accounts.clear();
    this->displayUserAccounts(accountsNames);
    this->onUnselectAccount();
}

//=================================================================================================
void UserAuthWidget::onAuthButtonPressed() {
    //Выбрать аккаунт, по которому кликали и кинуть сигнал вверху
    if(this->hasSelectedAccount) {
        emit signalAuthUser(this->selectedAccount);
    }
}

void UserAuthWidget::onAddButtonPressed() {
    //TODO: Вызвать диалоговое окно ввода имени
    UserDialog * nameDialog = new UserDialog();
    nameDialog->show();
    QObject::connect(nameDialog, &UserDialog::signalCreateNewUser, this, &UserAuthWidget::signalAddUser);
}

void UserAuthWidget::onEditButtonPressed() {
    //TODO: Вызвать диалоговое окно ввода имени
    UserDialog * nameDialog = new UserDialog(this->selectedAccount);
    nameDialog->show();
    QObject::connect(nameDialog, &UserDialog::signalEditUserName, this, &UserAuthWidget::onEditUserAccount);//TODO: Не туда коннектим
}


void UserAuthWidget::onRemoveButtonPressed() {
    if (hasSelectedAccount) {
        emit signalDeleteUser(this->selectedAccount);
    }
}

void UserAuthWidget::onCancelButtonPressed() {
    emit signalCancel();
}

void UserAuthWidget::onEditUserAccount(UserAccount account) {
    if (hasSelectedAccount) {
        emit signalEditUser(account);
    }
}
//=================================================================================================

void UserAuthWidget::onUserAccountClicked(UserAccount account) {

    this->selectedAccount = account;

    for(UserAccountPutton * b : this->accounts.values()) {
        b->setChecked(false);
    }

    UserAccountPutton * selectedAccount = accounts.value(account);
    selectedAccount->setChecked(true);

    this->onSelectAccount();

}

void UserAuthWidget::clearAccountsListWidgets() {
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
    this->hasSelectedAccount = true;
}

void UserAuthWidget::onUnselectAccount() {
    this->ui->auth_pushButton->setDisabled(true);
    this->ui->edit_pushButton->setDisabled(true);
    this->ui->remove_pushButton->setDisabled(true);
    this->hasSelectedAccount = false;
}

UserAuthWidget::~UserAuthWidget() {
    delete ui;
}
