#include "XMLManager.h"

LOAD_STATUS XMLManager::loadFile(QString fileName, QDomDocument* document)
{
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return INVALID_FILE;

    if (!document->setContent(&file))
    {
        file.close();
        return INVALID_CONTENT;
    }

    file.close();

    return OK;
}

LOAD_STATUS XMLManager::loadNode(QDomElement element, Node* node)
{
    if (element.attribute("ID") == 0)
    {
        delete node;
        return NO_NODE_ID;
    }

    if (element.attribute("Text") == 0)
    {
        delete node;
        return NO_NODE_TEXT;
    }

    node->setID(element.attribute("ID").toInt());
    node->setText(element.attribute("Text"));

    return OK;
}

LOAD_STATUS XMLManager::loadOption(QDomElement element, Option* option, Node* node)
{
    if (element.attribute("Text") == 0)
    {
        delete node;
        return NO_OPTION_TEXT;
    }

    if (element.attribute("Destination") == 0)
    {
        delete node;
        return NO_OPTION_DESTINATION_ID;
    }

    option->setText(element.attribute("Text"));
    option->setDestinationID(element.attribute("Destination").toInt());

    node->addOption(option);

    return OK;
}
