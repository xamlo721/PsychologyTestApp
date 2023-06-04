#ifndef INSTRUTIONTORSONWIDGET_H
#define INSTRUTIONTORSONWIDGET_H

#include <QWidget>

#include "ui_InstructionTorston.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class InstructionMain;
}
QT_END_NAMESPACE

class InstrutionTorsonWidget : public QWidget {

    Q_OBJECT

    public:
        explicit InstrutionTorsonWidget(QWidget *parent = nullptr);

    signals:

    public:
        Ui::InstructionTorstonWidget *uiInstructionTorston;

};

#endif // INSTRUTIONTORSONWIDGET_H
