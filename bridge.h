#ifndef BRIDGE_H
#define BRIDGE_H

#include <QObject>

#include <QList>

#include "astaralgorithm.h"

#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

typedef QVariantList ExpandedMatrix;


Q_DECLARE_METATYPE(ExpandedMatrix)


class Bridge : public QObject
{
    Q_OBJECT
public:
    explicit Bridge(QObject *parent = nullptr);

    Q_PROPERTY(int column READ column WRITE setColumn NOTIFY columnChanged)
    Q_PROPERTY(int row READ row WRITE setRow NOTIFY rowChanged)

    Q_PROPERTY(ExpandedMatrix expandedMatrix READ expandedMatrix WRITE setExpandedMatrix NOTIFY expandedMatrixChanged)

    Q_INVOKABLE void runAlgorithm();

    int column() const;
    int row() const;


    ExpandedMatrix expandedMatrix() const;

signals:

    void columnChanged(int column);
    void rowChanged(int row);

    void expandedMatrixChanged(ExpandedMatrix expandedMatrix);


public slots:

    void setColumn(int column);
    void setRow(int row);

    void setExpandedMatrix(ExpandedMatrix expandedMatrix);

    void restructGraphMatrix();

private:

    void logRowColChages();

    int m_column;
    int m_row;

    AStarAlgorithm algorithm;
    ExpandedMatrix m_expandedMatrix;

    void expandGraphMtrx(MatrixXi source);
    MatrixXi buildMatrix( ExpandedMatrix);
};

#endif // BRIDGE_H
