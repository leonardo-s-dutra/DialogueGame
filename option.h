#pragma once

#include <QObject>

class Option : public QObject
{
    Q_OBJECT
public:
    explicit Option(QObject *parent = nullptr);

    QString text() const;
    int destinationID() const;

    void setText(QString text);
    void setDestinationID(int destinationID);

private:
    QString Text;
    int DestinationID;
};