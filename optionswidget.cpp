#include "optionswidget.h"

OptionsWidget::OptionsWidget(QWidget *parent) : QWidget(parent)
{
    Buttons = new QButtonGroup(this);

    setLayout(new QVBoxLayout(this));
    layout()->setAlignment(Qt::AlignCenter);
    layout()->setSpacing(15);
}

void OptionsWidget::clearButtons()
{
    foreach(QAbstractButton *button, Buttons->buttons())
    {
        Buttons->removeButton(button);
        delete button;
    }
}

void OptionsWidget::loadButtons(Node *currentNode)
{
    foreach(Option * option, currentNode->options())
    {
        OptionButton* button = new OptionButton(option->text(), this);
        Buttons->addButton(button, option->destinationID());
        layout()->addWidget(button);
    }
}

QButtonGroup *OptionsWidget::buttons() const
{
    return Buttons;
}
