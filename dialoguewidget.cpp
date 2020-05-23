#include "dialoguewidget.h"

DialogueWidget::DialogueWidget(QWidget *parent) : QWidget(parent)
{
    TextArea = new QTextEdit(this);
    TextArea->setReadOnly(true);
    TextArea->setFontPointSize(10);

    setLayout(new QVBoxLayout(this));
    layout()->setAlignment(Qt::AlignCenter);
    layout()->addWidget(TextArea);
}

void DialogueWidget::updateText(QString npcText, QString playerText)
{
    TextArea->insertPlainText("\n\n----------------------------------------------------------------");

    insertPlayerText(playerText);
    insertNpcText(npcText);
}


void DialogueWidget::initText(QString text)
{
    insertNpcText(text);
}

void DialogueWidget::finishText()
{
    textArea()->insertPlainText("\n\nEND OF DIALOGUE");
}

QTextEdit* DialogueWidget::textArea() const
{
    return TextArea;
}

void DialogueWidget::eraseText()
{
    TextArea->clear();
}

void DialogueWidget::insertNpcText(QString text)
{
    TextArea->setFontWeight(QFont::Bold);
    TextArea->insertPlainText("[__NpcName__]: ");

    TextArea->setFontWeight(QFont::Normal);
    TextArea->insertPlainText(text);
}

void DialogueWidget::insertPlayerText(QString text)
{
    TextArea->setFontWeight(QFont::Bold);
    TextArea->insertPlainText("\n\nYou: ");

    TextArea->setFontWeight(QFont::Normal);
    TextArea->insertPlainText(text + "\n\n");
}