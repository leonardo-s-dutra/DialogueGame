#pragma once

#include <QObject>
#include <QtXml>
#include "node.h"
#include "xmlmanager.h"


class DialogueManager : public QObject
{
    Q_OBJECT
public:
    explicit DialogueManager(QObject *parent = nullptr);

    Node *getNode(int id);
    void addNode(Node* node);

    LOAD_STATUS load(QString fileName);

    void deallocate();

private:
    QList<Node*> nodes;
};