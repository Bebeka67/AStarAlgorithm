#include "bridge.h"

Bridge::Bridge(QObject *parent) : QObject(parent)
{

}
#include "bridge.h"

Bridge::Bridge(QObject *parent)
    : QObject(parent)
    , m_column(3)
    , m_row(3)
{

}

int Bridge::column() const
{
    return m_column;
}

int Bridge::row() const
{
    return m_row;
}

void Bridge::setColumn(int column)
{
    if (m_column == column)
        return;

    m_column = column;
    emit columnChanged(m_column);
}

void Bridge::setRow(int row)
{
    if (m_row == row)
        return;

    m_row = row;
    emit rowChanged(m_row);
}
