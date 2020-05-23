#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QSplitter>
#include "dialoguewidget.h"
#include "optionswidget.h"
#include "dialoguemanager.h"


class GameScreen : public QWidget
{
    Q_OBJECT
public:
    explicit GameScreen(QWidget *parent = nullptr);

    void init();
    void finish();

    DialogueWidget* getDialogueWidget() const;
    OptionsWidget* getOptionsWidget() const;

    QPushButton* returnButton() const;

public slots:
    void loadDialogue(QString path);
    void update(int id);

signals:
    void loadFailed(QString status);
    void loadOk();

private:
    DialogueWidget *dialogueWidget;
    OptionsWidget *optionsWidget;
    DialogueManager *dialogueManager;
    QPushButton *ReturnButton;
    QStackedWidget *stackedWidget;
};
