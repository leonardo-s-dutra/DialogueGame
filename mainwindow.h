#pragma once

#include <QMainWindow>
#include <QStackedWidget>
#include "startScreen.h"
#include "gameScreen.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);

public slots:
    void switchToGame();
    void switchToStart();

private:
    QStackedWidget *mainWidget;
    StartScreen *startScreen;
    GameScreen *gameScreen;
};