#ifndef INSTRUCTIONLIRIWIDGET_H
#define INSTRUCTIONLIRIWIDGET_H

#include <QWidget>

#include "ui_InstructionLiri.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class InstructionMain;
}
QT_END_NAMESPACE

class InstructionLiriWidget : public QWidget {

    Q_OBJECT

    public:
        explicit InstructionLiriWidget(QWidget *parent = nullptr);

    signals:

    public:
        Ui::InstructionLiriWidget *uiInstructionLiri;


};

#endif // INSTRUCTIONLIRIWIDGET_H
