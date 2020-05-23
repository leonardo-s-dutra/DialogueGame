#include "node.h"

Node::Node(QObject* parent) : QObject(parent)
{

}

int Node::hasOptions()
{
    return Options.count() > 0;
}

int Node::id() const
{
    return this->Id;
}

QString Node::text() const
{
    return this->Text;
}

QList<Option*> Node::options() const
{
    return this->Options;
}

void Node::setID(int Id)
{
    this->Id = Id;
}

void Node::setText(QString text)
{
    this->Text = text;
}

void Node::addOption(Option* option)
{
    this->Options.append(option);
}
