#include "node.h"

Node::Node()
{

}

Node::Node(int ind) : index(ind)
{

}

bool Node::operator==(const Node other)
{ return this->index == other.index ? true : false; }

bool Node::operator<(const Node &other) const
{ return this->fScore < other.fScore ? true : false; }

bool Node::operator<=(const Node other)
{ return this->fScore <= other.fScore ? true : false; }

//bool Node::operator!=(const Node other)
//{ return this->index != other.index ? true : false; }

void Node::operator=(const Node &other)
{
    this->coords = other.coords;
    this->index = other.index;
    this->fScore = other.fScore;
}

int Node::h(Node other)
{
    return 10 * (abs( this->coords.first - other.coords.first) + abs( this->coords.second - other.coords.second ));
}
