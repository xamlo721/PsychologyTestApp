#include "PsychoResultWidget.h"
#include "ui_PsychoResultWidget.h"
#include "common/ui/auth/UserDialog.h"

PsychoResultWidget::PsychoResultWidget(QWidget *parent) :  QWidget(parent), ui(new Ui::PsychoResultWidget) {
    ui->setupUi(this);
    QObject::connect(this->ui->cancel_pushButton, &QPushButton::clicked, this, &PsychoResultWidget::onCancelButtonPressed);
    ui->scrollArea->setLayout(new QVBoxLayout());
    ui->scrollArea->layout()->setAlignment(Qt::AlignTop);

    this->ui->auth_pushButton->setDisabled(true);
    this->ui->edit_pushButton->setDisabled(true);
    this->ui->remove_pushButton->setDisabled(true);
    this->hasSelectedAccount = false;
}

void PsychoResultWidget::displayNewAccount(UserAccount account) {

    if (accounts.contains(account)) {
        //TODO: сделать что-иньбудь
        return;
    }

    UserAccountPutton * button = new UserAccountPutton(account);
    this->ui->scrollArea->layout()->addWidget(button);
    accounts.insert(account, button);
    QObject::connect(button, &UserAccountPutton::signalSelected, this, &PsychoResultWidget::onUserAccountClicked);

}


void PsychoResultWidget::displayUserAccounts(QList<UserAccount> users) {
    this->clearAccountsListWidgets();
    this->accounts.clear();

    for (UserAccount account : users) {
        this->displayNewAccount(account);
    }
    this->onUnselectAccount();
}

void PsychoResultWidget::removeDisplayedAccount(UserAccount account) {
    this->accounts.remove(account);
    QList<UserAccount> accountsNames = this->accounts.keys();
    this->accounts.clear();
    this->displayUserAccounts(accountsNames);
    this->onUnselectAccount();
}
//=================================================================================================
void PsychoResultWidget::onAuthButtonPressed() {
    //Выбрать аккаунт, по которому кликали и кинуть сигнал вверху
    if(this->hasSelectedAccount) {
        emit signalUserResultClicked(this->selectedAccount);
    }
}

void PsychoResultWidget::onAddButtonPressed() {
    //TODO: Вызвать диалоговое окно ввода имени
//    UserDialog * nameDialog = new UserDialog();
//    nameDialog->show();
//    QObject::connect(nameDialog, &UserDialog::signalCreateNewUser, this, &PsychoResultWidget::signalLiriResultClicked);
}

void PsychoResultWidget::onEditButtonPressed() {
    //TODO: Вызвать диалоговое окно ввода имени
    UserDialog * nameDialog = new UserDialog(this->selectedAccount);
    nameDialog->show();
    QObject::connect(nameDialog, &UserDialog::signalEditUserName, this, &PsychoResultWidget::onEditUserAccount);//TODO: Не туда коннектим
}


void PsychoResultWidget::onRemoveButtonPressed() {
    if (hasSelectedAccount) {
        emit signalDeleteUser(this->selectedAccount);
    }
}



void PsychoResultWidget::onCancelButtonPressed() {

    //TODO: какие-то действия по закрытию окон
    emit signalCancelButtonPressed();
}


void PsychoResultWidget::onEditUserAccount(UserAccount account) {
    if (hasSelectedAccount) {
        emit signalEditUser(account);
    }
}
//=================================================================================================



void PsychoResultWidget::onUserAccountClicked(UserAccount account) {

    this->selectedAccount = account;

    for(UserAccountPutton * b : this->accounts.values()) {
        b->setChecked(false);
    }

    UserAccountPutton * selectedAccount = accounts.value(account);
    selectedAccount->setChecked(true);

    this->onSelectAccount();

}

void PsychoResultWidget::clearAccountsListWidgets() {
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

void PsychoResultWidget::onSelectAccount() {
    this->ui->auth_pushButton->setDisabled(false);
    this->ui->edit_pushButton->setDisabled(false);
    this->ui->remove_pushButton->setDisabled(false);
    this->hasSelectedAccount = true;
}

void PsychoResultWidget::onUnselectAccount() {
    this->ui->auth_pushButton->setDisabled(true);
    this->ui->edit_pushButton->setDisabled(true);
    this->ui->remove_pushButton->setDisabled(true);
    this->hasSelectedAccount = false;
}


PsychoResultWidget::~PsychoResultWidget() {
    delete ui;
}
