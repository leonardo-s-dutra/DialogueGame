#pragma once

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QButtonGroup>
#include "optionbutton.h"
#include "node.h"
#include "option.h"


class OptionsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit OptionsWidget(QWidget *parent = nullptr);

    void clearButtons();
    void loadButtons(Node *currentNode);

    void showExitButton();

    QButtonGroup *buttons() const;

private:
    QButtonGroup *Buttons;
};