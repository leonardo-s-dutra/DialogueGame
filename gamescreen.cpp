#include "gamescreen.h"

GameScreen::GameScreen(QWidget *parent) : QWidget(parent)
{
    dialogueWidget  = new DialogueWidget    (this);
    optionsWidget   = new OptionsWidget     (this);
    dialogueManager = new DialogueManager   (this);
    ReturnButton    = new QPushButton       ("Return", this);
    stackedWidget   = new QStackedWidget    (this);

    dialogueWidget->setMinimumHeight(400);
    ReturnButton->setFixedSize(120, 40);
    ReturnButton->setObjectName("Menu");

    QWidget *returnButtonWidget = new QWidget(this);
    returnButtonWidget->setLayout(new QVBoxLayout(this));
    returnButtonWidget->layout()->setAlignment(Qt::AlignCenter);
    returnButtonWidget->layout()->addWidget(ReturnButton);

    stackedWidget->addWidget(optionsWidget);
    stackedWidget->addWidget(returnButtonWidget);

    QSplitter *splitter = new QSplitter(Qt::Vertical, this);

    splitter->addWidget(dialogueWidget);
    splitter->addWidget(stackedWidget);

    splitter->setCollapsible(0, false);
    splitter->setCollapsible(1, false);

    setLayout(new QVBoxLayout(this));
    layout()->addWidget(splitter);

    connect(optionsWidget->buttons(), SIGNAL(buttonClicked(int)), this, SLOT(update(int)));
}

void GameScreen::init()
{
    stackedWidget->setCurrentIndex(0);

    Node *firstNode = dialogueManager->getNode(0);
    QString firstText = firstNode->text();

    dialogueWidget->initText(firstText);

    optionsWidget->loadButtons(firstNode);
}

void GameScreen::finish()
{
    dialogueWidget->finishText();

    dialogueManager->deallocate();

    stackedWidget->setCurrentIndex(1);
}

void GameScreen::update(int id)
{
    Node* currentNode = dialogueManager->getNode(id);

    QString currentText = currentNode->text();
    QString selectedText = optionsWidget->buttons()->button(id)->text();

    dialogueWidget->updateText(currentText, selectedText);

    optionsWidget->clearButtons();

    if (!currentNode->hasOptions())
        finish();

    else
        optionsWidget->loadButtons(currentNode);
}

void GameScreen::loadDialogue(QString path)
{
    switch (dialogueManager->load(path))
    {
    case INVALID_FILE:
        emit loadFailed("Dialogue must be a .xml file.");
        break;

    case INVALID_CONTENT:
        emit loadFailed("Could not set content to dialogue.");
        break;

    case NO_NODE_ID:
        emit loadFailed("Node with missing ID found.");
        break;

    case NO_NODE_TEXT:
        emit loadFailed("Node with missing text found.");
        break;

    case NO_OPTION_TEXT:
        emit loadFailed("Option with missing text found.");
        break;

    case NO_OPTION_DESTINATION_ID:
        emit loadFailed("Option with missing destination ID found.");
        break;

    case OK:
        emit loadOk();
        break;
    }
}

DialogueWidget *GameScreen::getDialogueWidget() const
{
    return dialogueWidget;
}

OptionsWidget *GameScreen::getOptionsWidget() const
{
    return optionsWidget;
}

QPushButton *GameScreen::returnButton() const
{
    return ReturnButton;
}
