#include "node.h"

Node::Node() : _x(0), _y(0)
{

}

void Node::setCoords(QPoint coords)
{
    _x = coords.x();
    _y = coords.y();
}

void Node::setName(QString name)
{
    this->_name = name;
}

void Node::setPrevios(Node* prev)
{
    this->_previous = prev;
}
