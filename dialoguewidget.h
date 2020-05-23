#pragma once

#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include "node.h"


class DialogueWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DialogueWidget(QWidget *parent = nullptr);

    void updateText(QString npcText, QString playerText);
    void initText(QString text);
    void finishText();
    void eraseText();

    QTextEdit *textArea() const;

private:
    void insertNpcText(QString text);
    void insertPlayerText(QString text);

    QTextEdit *TextArea;
    Node *currentNode;
};