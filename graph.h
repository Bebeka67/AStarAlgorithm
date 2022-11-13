#ifndef GRAPH_H
#define GRAPH_H

#include <Eigen/Dense>

using namespace Eigen;

class Graph
{
public:
    Graph(MatrixXi);

    MatrixXi graphMatrix() {return m_graphMatrix; }
    MatrixXi adjacencyMatrix() {return m_adjacencyMatrix; }
    int start() { return m_start; }
    int goal() { return m_goal; }

private:

    void findStartAndGoal();

    MatrixXi createGraphMatrix(int r, int c);
    MatrixXi createAdjacencyMatrix(MatrixXi sourceGraph);

    MatrixXi m_graphMatrix;
    MatrixXi m_adjacencyMatrix;
    int m_start =-2;
    int m_goal =-2;

};

#endif // GRAPH_H
