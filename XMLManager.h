#pragma once

#include <QtCore>
#include <QtXml/qdom.h>
#include "node.h"
#include "option.h"
#include "load_status.h"


class XMLManager
{
public:
    static LOAD_STATUS loadFile(QString fileName, QDomDocument *document);

    static LOAD_STATUS loadNode(QDomElement element, Node *node);

    static LOAD_STATUS loadOption(QDomElement element, Option* option, Node *node);

private:
    XMLManager() {}
};