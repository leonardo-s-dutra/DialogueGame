#pragma once

#include <QObject>

class Option : public QObject
{
	Q_OBJECT

public:
	Option(QObject *parent);
	~Option();
};
