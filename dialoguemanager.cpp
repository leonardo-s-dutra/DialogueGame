#include "dialoguemanager.h"

DialogueManager::DialogueManager(QObject* parent) : QObject(parent)
{

}

Node* DialogueManager::getNode(int id)
{
    return nodes.at(id);
}

void DialogueManager::addNode(Node* node)
{
    nodes.append(node);

    int ID = nodes.indexOf(node);

    node->setID(ID);
}

LOAD_STATUS DialogueManager::load(QString fileName)
{
    nodes.clear();

    QDomDocument document;

    LOAD_STATUS fileStatus = XMLManager::loadFile(fileName, &document);

    if (fileStatus != OK)
        return fileStatus;

    QDomElement dialogueRoot = document.firstChildElement();
    QDomNodeList domNodes = dialogueRoot.elementsByTagName("Node");

    for (int i = 0; i < domNodes.count(); i++)
    {
        QDomElement elementNode = domNodes.at(i).toElement();
        Node* dialogueNode = new Node(this);

        LOAD_STATUS nodeStatus = XMLManager::loadNode(elementNode, dialogueNode);

        if (nodeStatus != OK)
            return nodeStatus;

        addNode(dialogueNode);

        QDomNodeList domOptions = elementNode.elementsByTagName("Option");

        for (int j = 0; j < domOptions.count(); j++)
        {
            QDomElement elementOption = domOptions.at(j).toElement();
            Option* dialogueOption = new Option(dialogueNode);

            LOAD_STATUS optionStatus = XMLManager::loadOption(elementOption, dialogueOption, dialogueNode);

            if (optionStatus != OK)
                return optionStatus;
        }
    }

    return OK;
}

void DialogueManager::deallocate()
{
    foreach(Node *node, nodes)
    {
        delete node;
    }

    nodes.clear();
}
