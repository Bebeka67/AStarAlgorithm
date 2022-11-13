#include "bridge.h"

#include <QDebug>
#include <iostream>


Bridge::Bridge(QObject *parent)
    : QObject(parent)
    , m_column(3)
    , m_row(3)
{

    MatrixXi Graph(5,7);
    Graph.setZero();
    Graph(2,1) = 1;
    Graph(2,5) = 9;
    Graph(1,3) = -1;
    Graph(2,3) = -1;
    Graph(3,3) = -1;

    std::cout << Graph<<std::endl;

    setColumn(Graph.cols());
    setRow(Graph.rows());

    expandGraphMtrx(Graph);

    //qDebug() << m_expandedMatrix;

    //std::cout << createAdjacencyMatrix(Graph) <<std::endl;

    connect( this, SIGNAL(rowChanged(int)), this, SLOT(restructGraphMatrix()) );
    connect( this, SIGNAL(columnChanged(int)), this, SLOT(restructGraphMatrix()) );



}


void Bridge::restructGraphMatrix()
{

    MatrixXi blank(m_row, m_column);
    blank.setZero();

    expandGraphMtrx(blank);

    qDebug("triggered");

}


void Bridge::runAlgorithm()
{
    MatrixXi source = buildMatrix(expandedMatrix());

    MatrixXi result = algorithm.run(source);

    if( result == source )
    {
        qDebug() << "There is no path from Start node to Goal node;";
        return;
    }

    expandGraphMtrx(result);
}

void Bridge::expandGraphMtrx(MatrixXi source)
{
    ExpandedMatrix buffer;
    for(int i = 0; i < source.rows(); i++)
        for(int j = 0; j < source.cols(); j++)
        {


            buffer.append(source(i, j));
        }
    setExpandedMatrix(buffer);
}

MatrixXi Bridge::buildMatrix(ExpandedMatrix source)
{
    MatrixXi m(m_row,m_column);
    // i * m_graphMatrix.cols() + j

    for( int i = 0; i < m_row; i++ )
    {
        for( int j = 0; j < m_column; j++ )
        {
            m(i,j) = source[i * m_column + j].toInt();
        }
    }

    cout << "\nhere" <<endl;
    cout << m;

    return m;

}

int Bridge::column() const
{
    return m_column;
}

int Bridge::row() const
{
    return m_row;
}

ExpandedMatrix Bridge::expandedMatrix() const
{
    return m_expandedMatrix;
}

void Bridge::setColumn(int column)
{
    if (m_column == column)
        return;

    m_column = column;
    logRowColChages();
    emit columnChanged(m_column);
}

void Bridge::setRow(int row)
{
    if (m_row == row)
        return;
    m_row = row;
    logRowColChages();
    emit rowChanged(m_row);
}

void Bridge::setExpandedMatrix(ExpandedMatrix expandedMatrix)
{
    if (m_expandedMatrix == expandedMatrix)
        return;
    m_expandedMatrix = expandedMatrix;
    emit expandedMatrixChanged(m_expandedMatrix);
}


void Bridge::logRowColChages()
{
    qDebug() << QString("cpp: rows:%1  columns: %2").arg(m_row).arg(m_column);
}

