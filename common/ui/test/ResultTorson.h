#ifndef RESULTTORSON_H
#define RESULTTORSON_H

#include <QWidget>

#include "ui_ResultTorson.h"

#include "common/items/EnumTorsonResult.h"
#include "common/items/TorstonResult.h"


namespace Ui {
    class ResultTorson;
}

class ResultTorson : public QWidget {

    Q_OBJECT

    public:
        explicit ResultTorson(QWidget *parent = nullptr);
        ~ResultTorson();

        void showResult(TorstonResult result);

    public:
        Ui::ResultTorson *ui;
};

#endif // RESULTTORSON_H
