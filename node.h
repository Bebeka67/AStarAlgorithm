#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <QMap>


class Node
{
public:
    Node();
    Node(int ind);

    bool operator==(const Node other);

    bool operator<(const Node &other) const;

    bool operator<=(const Node other);

    bool operator!=(const Node other);

    void operator=(const Node &other);

    friend std::ostream &operator<<(std::ostream &out, Node &node)
    {
        out << (QString("Index: %1, Coords: (%2,%3), fScore: %4")
                .arg(node.index).arg(node.coords.first)
                .arg(node.coords.second)
                .arg(node.fScore))
               .toStdString() << std::endl;
        return out;
    }

    int h(Node other);

    QList<Node> neighbors;

    QPair<int,int> coords;

    int index;
    int costToPrevious = 0;
    int fScore = 0;
};

#endif // NODE_H
