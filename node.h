#pragma once

#include <QObject>
#include "option.h"

class Node : public QObject
{
    Q_OBJECT
public:
    explicit Node(QObject* parent = nullptr);

    int hasOptions();

    int id() const;
    QString text() const;
    QList<Option*> options() const;

    void setID(int ID);
    void setText(QString text);
    void addOption(Option* option);

private:
    int Id;
    QString Text;
    QList<Option*> Options;
};
