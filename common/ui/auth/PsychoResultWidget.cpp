#include "PsychoResultWidget.h"
#include "ui_PsychoResultWidget.h"
#include "common/ui/auth/UserDialog.h"
#include "common/ui/auth/ChangePasswordDialog.h"
#include <cmath>

PsychoResultWidget::PsychoResultWidget(QWidget *parent) :  QWidget(parent), ui(new Ui::PsychoResultWidget) {
    ui->setupUi(this);
    QObject::connect(this->ui->showResult_pushButton, &QPushButton::clicked, this, &PsychoResultWidget::onShowResultButtonPressed);
    QObject::connect(this->ui->showprotocol_pushButton, &QPushButton::clicked, this, &PsychoResultWidget::onShowProtocolPressed);
    QObject::connect(this->ui->changePassword_pushButton, &QPushButton::clicked, this, &PsychoResultWidget::onChangePasswdPressed);
    QObject::connect(this->ui->print_pushButton, &QPushButton::clicked, this, &PsychoResultWidget::onPrintButtonPressed);
    QObject::connect(this->ui->remove_pushButton, &QPushButton::clicked, this, &PsychoResultWidget::onRemoveButtonPressed);
    QObject::connect(this->ui->cancel_pushButton, &QPushButton::clicked, this, &PsychoResultWidget::onCancelButtonPressed);

    ui->scrollArea_users->setLayout(new QVBoxLayout());
    ui->scrollArea_users->layout()->setAlignment(Qt::AlignTop);

    ui->scrollArea_results->setLayout(new QVBoxLayout());
    ui->scrollArea_results->layout()->setAlignment(Qt::AlignTop);

    this->ui->showResult_pushButton->setDisabled(true);
    this->ui->showprotocol_pushButton->setDisabled(true);
    this->ui->print_pushButton->setDisabled(true);
    this->ui->remove_pushButton->setDisabled(true);

    this->hasSelectedAccount = false;
    this->hasSelectedResult = false;

}

void PsychoResultWidget::changeAccountName(UserAccount account) {
        //Не нужна
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

void PsychoResultWidget::onPrintButtonPressed() {

    //Code plase

//    QTextEdit parent;
//    parent.setText("We are the world!");
//    parent.show();

//    QString filename = QFileDialog::getOpenFileName(&parent,"Open File",QString(),"Pdf File(*.pdf)");
//    qDebug()<<"Print file name is "<<filename;
//    if(!filename.isEmpty()) {
//        if(QFileInfo(filename).suffix().isEmpty()) {
//            filename.append(".pdf");
//        }

//        QPrinter printer(QPrinter::HighResolution);
//        printer.setOutputFormat(QPrinter::PdfFormat);
//        printer.setOutputFileName(filename);
//        QPrintDialog*dlg = new QPrintDialog(&printer,&parent);
//        dlg->setWindowTitle(QObject::tr("Print Document"));

//        if(dlg->exec() == QDialog::Accepted) {
//            parent.print(&printer);
//        }
//        delete dlg;
//    }




//    QPrinter printer(QPrinter::PrinterResolution);
//    printer.setOutputFormat(QPrinter::PdfFormat);
//    printer.setOutputFileName("document.pdf");


//    QPainter painter;
//    if (!painter.begin(&printer)) {
//        qWarning("Failed to open printer");
//        return;
//    }

//    painter.drawText(100, 100, "Hello, world!");
//    painter.end();



//    QPrintDialog printDialog(printer, parent);
//    if (printDialog.exec() == QDialog::Accepted) {
//        // print ...
//    }

    if (this->selectedResultType == EnumTestType::Liri) {
        this->printLiriResult();
    } else {
        this->printTorsronResult();
    }
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
    this->ui->print_pushButton->setDisabled(false);
    this->ui->remove_pushButton->setDisabled(false);
    this->hasSelectedResult = true;
}

void PsychoResultWidget::onUnselectResult() {
    this->ui->showResult_pushButton->setDisabled(true);
    this->ui->showprotocol_pushButton->setDisabled(true);
    this->ui->print_pushButton->setDisabled(true);
    this->ui->remove_pushButton->setDisabled(true);
    this->hasSelectedResult = false;
}

void PsychoResultWidget::onPasswordChanged(QString newPassword) {
    emit signalPasswordChanged(newPassword);
}

void PsychoResultWidget::syncProtocols(QMap <UserAccount, QPair<QList<AnswerProtocol>, QList<AnswerProtocol>>> protocols) {
    this->protocols = protocols;
}

void PsychoResultWidget::printLiriResult() {
    QTextEdit * tempBuffer = new QTextEdit();

            tempBuffer->setHtml("<!DOCTYPE HTML PUBLIC -//W3C//DTD HTML 4.0//EN" "http://www.w3.org/TR/REC-html40/strict.dtd\">"
                                "<html>"

                                "<head>"
                                    "<meta name=\"qrichtext\" content=\"1\" />"
                                    "<style type=\"text/css\">"
                                        "p,"
                                        "li {"
                                            "white-space: pre-wrap;"
                                        "}"
                                    "</style>"
                                "</head>"

                                "<body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">"

                                    "<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:150%;\">"
                                        "<span style=\" font-family:'Montserrat Medium'; font-size:24pt; color:#000000;\">	"
                                            "Результат участника: " + this->selectedAccount.getName() +
                                        "</span>"
                                    "</p>"
                                    "<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:150%;\">"
                                        "<span style=\" font-family:'Montserrat Medium'; font-size:16pt; color:#000000;\">	"
                                            "Авторитарность: " + QString::number(std::round(this->selectedLiriResult.st1*16.0 / 100)) +
                                        "</span>"
                                    "</p>"
                                        "<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:150%;\">"
                                            "<span style=\" font-family:'Montserrat Medium'; font-size:16pt; color:#000000;\">	"
                                                "Эгоистичность: " + QString::number(std::round(this->selectedLiriResult.st2*16.0 / 100)) +
                                            "</span>"
                                        "</p>"
                                            "<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:150%;\">"
                                                "<span style=\" font-family:'Montserrat Medium'; font-size:16pt; color:#000000;\">	"
                                                    "Агрессивность: " + QString::number(std::round(this->selectedLiriResult.st3*16.0 / 100)) +
                                                "</span>"
                                            "</p>"
                                                "<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:150%;\">"
                                                    "<span style=\" font-family:'Montserrat Medium'; font-size:16pt; color:#000000;\">	"
                                                        "Подозрительность: " + QString::number(std::round(this->selectedLiriResult.st4*16.0 / 100)) +
                                                    "</span>"
                                                "</p>"
                                                    "<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:150%;\">"
                                                        "<span style=\" font-family:'Montserrat Medium'; font-size:16pt; color:#000000;\">	"
                                                            "Подчиняемость: " + QString::number(std::round(this->selectedLiriResult.st5*16.0 / 100)) +
                                                        "</span>"
                                                    "</p>"
                                                        "<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:150%;\">"
                                                            "<span style=\" font-family:'Montserrat Medium'; font-size:16pt; color:#000000;\">	"
                                                                "Зависимость: " + QString::number(std::round(this->selectedLiriResult.st6*16.0 / 100)) +
                                                            "</span>"
                                                        "</p>"
                                                            "<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:150%;\">"
                                                                "<span style=\" font-family:'Montserrat Medium'; font-size:16pt; color:#000000;\">	"
                                                                    "Дружелюбность: " + QString::number(std::round(this->selectedLiriResult.st7*16.0 / 100)) +
                                                                "</span>"
                                                            "</p>"
                                                                "<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:150%;\">"
                                                                    "<span style=\" font-family:'Montserrat Medium'; font-size:16pt; color:#000000;\">	"
                                                                        "Альтруистичность: " + QString::number(std::round(this->selectedLiriResult.st8*16.0 / 100)) +
                                                                    "</span>"
                                                                "</p>"

                                "</body>"

                                "</html>");


//    tempBuffer->show();//Просто посмотреть что получилось.



    QString filename = QFileDialog::getSaveFileName(tempBuffer, "Open File", QString(), "Pdf File(*.pdf)");
    qDebug() << "Print file name is " << filename;
    if(!filename.isEmpty()) {
        if(QFileInfo(filename).suffix().isEmpty()) {
            filename.append(".pdf");
        }

        QPrinter printer(QPrinter::HighResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(filename);

        QTextDocument doc;
        doc.setHtml(tempBuffer->toHtml());
        doc.print(&printer);
    }

    delete tempBuffer;
}


void PsychoResultWidget::printTorsronResult() {

    QTextEdit * tempBuffer = new QTextEdit();

    switch (this->selectedTorstonResult.result) {

        case EnumTorsonResult::VeryLow :
        case EnumTorsonResult::Low :
        case EnumTorsonResult::Medium : {
            tempBuffer->setHtml("<!DOCTYPE HTML PUBLIC -//W3C//DTD HTML 4.0//EN" "http://www.w3.org/TR/REC-html40/strict.dtd\">"
                                "<html>"

                                "<head>"
                                    "<meta name=\"qrichtext\" content=\"1\" />"
                                    "<style type=\"text/css\">"
                                        "p,"
                                        "li {"
                                            "white-space: pre-wrap;"
                                        "}"
                                    "</style>"
                                "</head>"

                                "<body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">"

                                    "<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:150%;\">"
                                        "<span style=\" font-family:'Montserrat Medium'; font-size:24pt; color:#000000;\">	"
                                            "Результат участника: " + this->selectedAccount.getName() +
                                        "</span>"
                                    "</p>"

                                    "<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:150%;\">"
                                        "<span style=\" font-family:'Montserrat Medium'; font-size:16pt; color:#000000;\">	"
                                            "Полезависимые индивиды демонстрируют преимущественную ориентацию на внешние факторы при решении проблем."
                                        "</span>"
                                    "</p>"
                                    "<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:150%;\">"
                                        "<span style=\" font-family:'Montserrat Medium'; font-size:16pt; color:#000000;\">	"
                                            "У Вас более рациональная стратегия запоминания и воспроизведения, более развиты селективное внимание и контролирующие процессы."
                                        "</span>"
                                    "</p>"
                                    "<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:150%;\">"
                                        "<span style=\" font-family:'Montserrat Medium'; font-size:16pt; color:#000000;\">	"
                                            "Вы отличаетесь худшим познанием своего поведения, большей пассивностью в отношении к окружающему, большей внушаемостью и зависимостью от группы. "
                                            "При этом Вы легче разрешаете конфликтные ситуации."
                                        "</span>"
                                    "</p>"
                                "</body>"

                                "</html>");
            break;
        }

        case EnumTorsonResult::High :
        case EnumTorsonResult::VeryHigh : {
        tempBuffer->setHtml("<!DOCTYPE HTML PUBLIC -//W3C//DTD HTML 4.0//EN" "http://www.w3.org/TR/REC-html40/strict.dtd\">"
                            "<html>"

                            "<head>"
                                "<meta name=\"qrichtext\" content=\"1\" />"
                                "<style type=\"text/css\">"
                                    "p,"
                                    "li {"
                                        "white-space: pre-wrap;"
                                    "}"
                                "</style>"
                            "</head>"

                            "<body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">"

                                "<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:150%;\">"
                                    "<span style=\" font-family:'Montserrat Medium'; font-size:24pt; color:#000000;\">	"
                                        "Результат участника: " + this->selectedAccount.getName() +
                                    "</span>"
                                "</p>"

                                "<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:150%;\">"
                                    "<span style=\" font-family:'Montserrat Medium'; font-size:16pt; color:#000000;\">	"
                                        "Вы не самый социально-активный человек, больше проявляете интерес к теории и достижению цели. "
                                    "</span>"
                                "</p>"
                                "<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:150%;\">"
                                    "<span style=\" font-family:'Montserrat Medium'; font-size:16pt; color:#000000;\">	"
                                        "Для Вас характерна преимущественная ориентация на внутренние эталоны упорядочивания внешних впечатлений в условиях, когда навязываются неадекватные формы отражения внешнего мира. "
                                        "Вам свойственна устойчивость и адекватное восприятие предметного мира. Вы независимы от общества в большинстве ситуаций, а при выборе своей цели игнорируете окружение. "
                                    "</span>"
                                "</p>"
                                "<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:150%;\">"
                                    "<span style=\" font-family:'Montserrat Medium'; font-size:16pt; color:#000000;\">	"
                                        "Для Вас характерна высокая аналитичность, позволяющая Вам легко структурировать окружающую среду, и большая склонность полагаться на свои собственные оценки, мнения, впечатления."
                                    "</span>"
                                "</p>"
                            "</body>"

                            "</html>");
        break;
        }

    }

//    tempBuffer->show();//Просто посмотреть что получилось.



    QString filename = QFileDialog::getSaveFileName(tempBuffer, "Open File", QString(), "Pdf File(*.pdf)");
    qDebug() << "Print file name is " << filename;
    if(!filename.isEmpty()) {
        if(QFileInfo(filename).suffix().isEmpty()) {
            filename.append(".pdf");
        }

        QPrinter printer(QPrinter::HighResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(filename);

        QTextDocument doc;
        doc.setHtml(tempBuffer->toHtml());
        doc.print(&printer);
    }

    delete tempBuffer;
}


PsychoResultWidget::~PsychoResultWidget() {
    delete ui;
}
