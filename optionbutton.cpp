#include "optionbutton.h"

OptionButton::OptionButton(QString text, QWidget* parent) : QPushButton(text, parent)
{
    setObjectName("Option");
    setFont(QFont("Calibri", 9));
    setFlat(true);
    setCursor(Qt::PointingHandCursor);
}

void OptionButton::enterEvent(QEvent *event)
{
    Q_UNUSED(event);

    QFont font("Calibri", 9);
    font.setBold(true);
    setFont(font);
}

void OptionButton::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);

    QFont font("Calibri", 9);
    font.setBold(false);
    setFont(font);
}