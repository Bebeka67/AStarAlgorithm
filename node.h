#ifndef NODE_H
#define NODE_H

#include <QPoint>
#include <QString>

class Node
{
public:
    Node();

    void setName(QString name);
    void setCoord(QPoint coords);
    void setPrevios(Node* prev);

    QPoint coords() { return QPoint(_x, _y); }
    Node* previous() { return _previous; }

    bool operator ==(const Node& other)
    {
        if( this->_x != other._x )
            return false;
        if( this->_y != other._y )
            return false;

        if( this->_name != other._name )
            return false;
        return true;
    }

private:


    QString _name;

    int _x;
    int _y;
};

#endif // NODE_H
