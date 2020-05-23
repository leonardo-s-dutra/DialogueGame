#pragma once

#include <QObject>

class DialogueManager : public QObject
{
	Q_OBJECT

public:
	DialogueManager(QObject *parent);
	~DialogueManager();
};
