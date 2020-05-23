#pragma once

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QFileDialog>


class StartScreen : public QWidget
{
    Q_OBJECT
public:
    explicit StartScreen(QWidget* parent = nullptr);

public slots:
    void getFile();
    void showError(QString message);

signals:
    void fileSelected(QString path);
};
