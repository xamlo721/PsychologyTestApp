#include "PsychoResultWidget.h"
#include "ui_PsychoResultWidget.h"
#include "common/ui/auth/UserDialog.h"
#include "common/ui/auth/ChangePasswordDialog.h"

PsychoResultWidget::PsychoResultWidget(QWidget *parent) :  QWidget(parent), ui(new Ui::PsychoResultWidget) {
    ui->setupUi(this);
    QObject::connect(this->ui->showResult_pushButton, &QPushButton::clicked, this, &PsychoResultWidget::onShowResultButtonPressed);
    QObject::connect(this->ui->showprotocol_pushButton, &QPushButton::clicked, this, &PsychoResultWidget::onShowProtocolPressed);
    QObject::connect(this->ui->changePassword_pushButton, &QPushButton::clicked, this, &PsychoResultWidget::onChangePasswdPressed);
    QObject::connect(this->ui->remove_pushButton, &QPushButton::clicked, this, &PsychoResultWidget::onRemoveButtonPressed);
    QObject::connect(this->ui->cancel_pushButton, &QPushButton::clicked, this, &PsychoResultWidget::onCancelButtonPressed);

    ui->scrollArea_users->setLayout(new QVBoxLayout());
    ui->scrollArea_users->layout()->setAlignment(Qt::AlignTop);

    ui->scrollArea_results->setLayout(new QVBoxLayout());
    ui->scrollArea_results->layout()->setAlignment(Qt::AlignTop);

    this->ui->showResult_pushButton->setDisabled(true);
    this->ui->showprotocol_pushButton->setDisabled(true);
    this->ui->remove_pushButton->setDisabled(true);

    this->hasSelectedAccount = false;
    this->hasSelectedResult = false;

}

void PsychoResultWidget::changeAccountName(UserAccount account) {

}

void PsychoResultWidget::displayNewAccount(UserAccount account) {

    if (accounts.contains(account)) {
        //TODO: сделать что-иньбудь
        return;
    }

    UserAccountPutton * button = new UserAccountPutton(account);
    this->ui->scrollArea_users->layout()->addWidget(button);
    accounts.insert(account, button);
    QObject::connect(button, &UserAccountPutton::signalSelected, this, &PsychoResultWidget::onUserAccountClicked);

}

void PsychoResultWidget::displayNewResult(TorstonResult result) {

    UserReslitButton * button = new UserReslitButton(result);
    if (this->selectedAccount == result.user) {
        this->ui->scrollArea_results->layout()->addWidget(button);
    }
    QList<UserReslitButton * > buttons = this->displayesResults.value(result.user);
    buttons.append(button);
    QObject::connect(button, &UserReslitButton::signalLiriResultClicked, this, &PsychoResultWidget::onLiriResultClicked);
    QObject::connect(button, &UserReslitButton::signalTorstonResultClicked, this, &PsychoResultWidget::onTorstonResultClicked);

    this->displayesResults.insert(result.user, buttons);
}

void PsychoResultWidget::displayNewResult(LiriResult result) {
    UserReslitButton * button = new UserReslitButton(result);
    if (this->selectedAccount == result.user) {
        this->ui->scrollArea_results->layout()->addWidget(button);
    }
    QList<UserReslitButton * > buttons = this->displayesResults.value(result.user);
    buttons.append(button);
    QObject::connect(button, &UserReslitButton::signalLiriResultClicked, this, &PsychoResultWidget::onLiriResultClicked);
    QObject::connect(button, &UserReslitButton::signalTorstonResultClicked, this, &PsychoResultWidget::onTorstonResultClicked);
    this->displayesResults.insert(result.user, buttons);
}

void PsychoResultWidget::displayUserAccounts(QList<UserAccount> users) {
    this->clearAccountsListWidgets();
    this->accounts.clear();

    for (UserAccount account : users) {
        this->displayNewAccount(account);
    }
    this->hasSelectedAccount = false;
    this->onUnselectResult();
    this->clearResultsListWidgets();
    this->displayesResults.clear();
}

void PsychoResultWidget::displayUserResults(QMap <UserAccount, QPair<QList<LiriResult>, QList<TorstonResult>>> results) {

    this->clearResultsListWidgets();
    this->displayesResults.clear();
    this->results = results;

    for (UserAccount user : results.keys()) {
        if (!this->displayesResults.contains(user)) {//Если такого нету, то вставить. Всё же просто
            this->displayesResults.insert(user, QList<UserReslitButton * >() );
        }

        if (this->selectedAccount == user) {
            for (LiriResult liri : results.value(user).first) {
                this->displayNewResult(liri);
            }
            for (TorstonResult tors : results.value(user).second) {
                this->displayNewResult(tors);
            }
        }
    }

}

void PsychoResultWidget::removeDisplayedAccount(UserAccount account) {
    this->accounts.remove(account);
    QList<UserAccount> accountsNames = this->accounts.keys();
    this->accounts.clear();
    this->displayUserAccounts(accountsNames);
    this->hasSelectedAccount = false;
    this->onUnselectResult();
    this->clearResultsListWidgets();
    this->displayesResults.clear();
}

void PsychoResultWidget::removeDisplayedResult(UserAccount account, TorstonResult result) {

    QPair<QList<LiriResult>, QList<TorstonResult>> allresults = this->results.value(account);
    QList<TorstonResult> torstonResults = allresults.second;
    torstonResults.removeOne(result);
    allresults.second = torstonResults;
    this->results.insert(account, allresults);
    this->displayUserResults(this->results);
}

void PsychoResultWidget::removeDisplayedResult(UserAccount account, LiriResult result) {
    QPair<QList<LiriResult>, QList<TorstonResult>> allresults = this->results.value(account);
    QList<LiriResult> liriResults = allresults.first;
    liriResults.removeOne(result);
    allresults.first = liriResults;
    this->results.insert(account, allresults);
    this->displayUserResults(this->results);
}


//=================================================================================================
void PsychoResultWidget::onShowResultButtonPressed() {
    //Выбрать аккаунт, по которому кликали и кинуть сигнал вверху
    if(this->hasSelectedAccount) {
        if (this->selectedResultType == EnumTestType::Liri) {
            emit signalLiriResultClicked(this->selectedLiriResult);
        } else {
            emit signalTorstonResultClicked(this->selectedTorstonResult);
        }
    }
}

void PsychoResultWidget::onShowProtocolPressed() {
    //Выбрать аккаунт, по которому кликали и кинуть сигнал вверху

    QPair<QList<AnswerProtocol>, QList<AnswerProtocol>> allUserProtocols = protocols.value(this->selectedAccount);

    if(this->hasSelectedAccount) {
        if (this->selectedResultType == EnumTestType::Liri) {
            for (AnswerProtocol p : allUserProtocols.first) {
                if (p.resultID == this->selectedLiriResult.resultID) {
                    emit signalProtocolClicked(p);
                }
            }
        } else {
            for (AnswerProtocol p : allUserProtocols.second) {
                if (p.resultID == this->selectedTorstonResult.resultID) {
                    emit signalProtocolClicked(p);
                }
            }
        }
    }
}

void PsychoResultWidget::onChangePasswdPressed() {
    //TODO: Вызвать диалоговое окно ввода имени
    ChangePasswordDialog * changePasswd = new ChangePasswordDialog();
    changePasswd->show();
    QObject::connect(changePasswd, &ChangePasswordDialog::signalPasswordChanged, this, &PsychoResultWidget::onPasswordChanged);

}


void PsychoResultWidget::onRemoveButtonPressed() {
    if (hasSelectedAccount) {
        if (this->selectedResultType == EnumTestType::Liri) {
            emit signalDeleteLiriResult(this->selectedAccount, this->selectedLiriResult);
        } else {
            emit signalDeleteTorstonResult(this->selectedAccount, this->selectedTorstonResult);
        }
    }
}

void PsychoResultWidget::onCancelButtonPressed() {

    //TODO: какие-то действия по закрытию окон
    emit signalCancelButtonPressed();
}


//=================================================================================================

void PsychoResultWidget::onLiriResultClicked(LiriResult result) {
    selectedResultType = EnumTestType::Liri;
    this->selectedLiriResult = result;
    this->onSelectResult();

    for(UserReslitButton * r : this->displayesResults.value(this->selectedAccount)) {
        r->setChecked(false);
        if (r->getResultId() == result.resultID) {
            r->setChecked(true);
        }
    }
}

void PsychoResultWidget::onTorstonResultClicked(TorstonResult result) {
    selectedResultType = EnumTestType::Torston;
    this->selectedTorstonResult = result;
    this->onSelectResult();


    for(UserReslitButton * r : this->displayesResults.value(this->selectedAccount)) {
        r->setChecked(false);
        if (r->getResultId() == result.resultID) {
            r->setChecked(true);
        }
    }

}

void PsychoResultWidget::onUserAccountClicked(UserAccount account) {

    this->selectedAccount = account;
    this->hasSelectedAccount = true;

    for(UserAccountPutton * b : this->accounts.values()) {
        b->setChecked(false);
    }

    UserAccountPutton * selectedAccount = accounts.value(account);
    selectedAccount->setChecked(true);

    this->clearResultsListWidgets();
    this->displayesResults.clear();

    if (!this->displayesResults.contains(account)) {//Если такого нету, то вставить. Всё же просто
        this->displayesResults.insert(account, QList<UserReslitButton * >() );
    }

    if (this->selectedAccount == account) {
        for (LiriResult liri : results.value(account).first) {
            this->displayNewResult(liri);
        }
        for (TorstonResult tors : results.value(account).second) {
            this->displayNewResult(tors);
        }
    }

}

void PsychoResultWidget::clearAccountsListWidgets() {
    QWidget * m_view = this->ui->scrollArea_users;
    if ( m_view->layout() != NULL ) {
        QLayoutItem* item;
        while ( ( item = m_view->layout()->takeAt( 0 ) ) != NULL ) {
            delete item->widget();
            delete item;
        }
        //delete m_view->layout();
    }
}
void PsychoResultWidget::clearResultsListWidgets() {
    QWidget * m_view = this->ui->scrollArea_results;
    if ( m_view->layout() != NULL ) {
        QLayoutItem* item;
        while ( ( item = m_view->layout()->takeAt( 0 ) ) != NULL ) {
            delete item->widget();
            delete item;
        }
        //delete m_view->layout();
    }
}

void PsychoResultWidget::onSelectResult() {
    this->ui->showResult_pushButton->setDisabled(false);
    this->ui->showprotocol_pushButton->setDisabled(false);
    this->ui->remove_pushButton->setDisabled(false);
    this->hasSelectedResult = true;
}

void PsychoResultWidget::onUnselectResult() {
    this->ui->showResult_pushButton->setDisabled(true);
    this->ui->showprotocol_pushButton->setDisabled(true);
    this->ui->remove_pushButton->setDisabled(true);
    this->hasSelectedResult = false;
}

void PsychoResultWidget::onPasswordChanged(QString newPassword) {
    emit signalPasswordChanged(newPassword);
}

void PsychoResultWidget::syncProtocols(QMap <UserAccount, QPair<QList<AnswerProtocol>, QList<AnswerProtocol>>> protocols) {
    this->protocols = protocols;
}


PsychoResultWidget::~PsychoResultWidget() {
    delete ui;
}
