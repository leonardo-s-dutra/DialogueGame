#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    mainWidget = new QStackedWidget(this);
    startScreen = new StartScreen(this);
    gameScreen = new GameScreen(this);

    mainWidget->addWidget(startScreen);
    mainWidget->addWidget(gameScreen);

    connect(startScreen,                SIGNAL(fileSelected(QString)),  gameScreen,     SLOT(loadDialogue(QString)) );
    connect(gameScreen,                 SIGNAL(loadFailed(QString)),    startScreen,    SLOT(showError(QString))    );
    connect(gameScreen,                 SIGNAL(loadOk()),               this,           SLOT(switchToGame())        );
    connect(gameScreen->returnButton(), SIGNAL(clicked()),              this,           SLOT(switchToStart())       );

    setCentralWidget(mainWidget);

    setMinimumSize(700, 800);

    setWindowTitle("Dialogue");
}

void MainWindow::switchToGame()
{
    mainWidget->setCurrentIndex(1);
    gameScreen->init();
}

void MainWindow::switchToStart()
{
    gameScreen->getDialogueWidget()->eraseText();
    mainWidget->setCurrentIndex(0);
}
