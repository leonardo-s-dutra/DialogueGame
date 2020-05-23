#include "option.h"

Option::Option(QObject *parent) : QObject(parent)
{

}

QString Option::text() const
{
    return this->Text;
}

int Option::destinationID() const
{
    return this->DestinationID;
}

void Option::setText(QString text)
{
    this->Text = text;
}

void Option::setDestinationID(int destinationID)
{
    this->DestinationID = destinationID;
}
