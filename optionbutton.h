#pragma once

#include <QWidget>
#include <QPushButton>
#include "option.h"


class OptionButton : public QPushButton
{
    Q_OBJECT
public:
    OptionButton(QString text, QWidget *parent = nullptr);

    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);

signals:
    void selected(int destinationID);

};