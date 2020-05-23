#pragma once

#include <QObject>

class Node : public QObject
{
	Q_OBJECT

public:
	Node(QObject *parent);
	~Node();
};
