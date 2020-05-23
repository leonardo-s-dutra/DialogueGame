#include "startscreen.h"

StartScreen::StartScreen(QWidget* parent) : QWidget(parent)
{
    setLayout(new QVBoxLayout(this));
    layout()->setAlignment(Qt::AlignCenter);

    QPushButton* button = new QPushButton("Open file", this);
    button->setObjectName("Menu");
    button->setFixedSize(120, 40);

    layout()->addWidget(button);

    connect(button, SIGNAL(clicked()), this, SLOT(getFile()));
}

void StartScreen::getFile()
{
    QString path = QFileDialog::getOpenFileName(this,
                                                "Open file",
                                                "C:/",
                                                "*.xml");

    if (!path.isEmpty())
        emit fileSelected(path);
}

void StartScreen::showError(QString message)
{
    QMessageBox::critical(this, "Error", message);
}
