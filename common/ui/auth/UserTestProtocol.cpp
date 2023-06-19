#include "UserTestProtocol.h"
#include "ui_UserTestProtocol.h"

UserTestProtocol::UserTestProtocol(QWidget *parent) : QWidget(parent), ui(new Ui::UserTestProtocol) {
    ui->setupUi(this);
    QObject::connect(this->ui->tothemain, &QPushButton::clicked, this, &UserTestProtocol::signalCancel);
}

void UserTestProtocol::showProtocol(AnswerProtocol protocol) {
    this->ui->textEdit->setText("Протокол пользователя: " + protocol.user.getName() + "\n");

    for (int i = 0; i < protocol.answers.first.size(); i++) {
        QString protocolRecord = protocol.answers.first.at(i) + "   :   " + protocol.answers.second.at(i) + "\n";
        this->ui->textEdit->append(protocolRecord);

    }

}

UserTestProtocol::~UserTestProtocol() {
    delete ui;
}
