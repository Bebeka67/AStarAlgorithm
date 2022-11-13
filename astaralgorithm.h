#ifndef ASTARALGORITHM_H
#define ASTARALGORITHM_H

#include "graph.h"
#include "node.h"

#include <QMap>
#include <QDebug>

using namespace std;
class AStarAlgorithm
{

public:
    AStarAlgorithm();

    MatrixXi run(MatrixXi);




private:    // Metods

    QMap<int, Node> createNodeMapFromGraphMatrix( MatrixXi );
    Node createNodeFromGraph(int, int, MatrixXi);

    QList<int> A_Star(Node,Node, QMap<int, Node>);
    QList<int> reconstructPath(QMap<int, Node>, Node);
    QList<Node> findNeighborsFor(Node, Graph,QMap<int, Node>);

    MatrixXi mapThePath(QList<int>, Graph);

private:    // Data



    Graph* m_graph;

    QMap<int, Node> NodeMap;  // ключ - развернутый индекс, значение - вершина.

};

#endif // ASTARALGORITHM_H
