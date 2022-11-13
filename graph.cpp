#include "graph.h"

Graph::Graph(MatrixXi data)
{ 
    m_graphMatrix = data;
    findStartAndGoal();
    m_adjacencyMatrix = createAdjacencyMatrix(m_graphMatrix);
}

void Graph::findStartAndGoal()
{
    for(int i = 0; i < m_graphMatrix.rows(); i++)
        for(int j = 0; j < m_graphMatrix.cols(); j++)
        {
            if( m_graphMatrix(i,j) == 1 )
                m_start = i * m_graphMatrix.cols() + j;
            if( m_graphMatrix(i,j) == 9 )
                m_goal = i * m_graphMatrix.cols() + j;
            if( m_start != -2 && m_goal != -2 )
                return;
        }
}

MatrixXi Graph::createAdjacencyMatrix(MatrixXi sourceGraph)
{
    MatrixXi adjacencyMatrix(sourceGraph.size(),sourceGraph.size());
    adjacencyMatrix.setZero();

    for(int i = 0; i < sourceGraph.rows(); i++)
        for(int j = 0; j < sourceGraph.cols(); j++)
        {
            if(sourceGraph(i,j) == -1)
                continue;

            if( (i > 0) &&  (sourceGraph(i-1,j) != -1))  // Проверка верхней клетки
            {
                adjacencyMatrix( (i * sourceGraph.cols() + j), ((i-1) * sourceGraph.cols() + j))  = 10;
            }
            if( ((j < sourceGraph.cols() - 1) && sourceGraph(i,j+1) != -1))  // Проверка правой клетки
            {
                adjacencyMatrix( (i * sourceGraph.cols() + j), (i * sourceGraph.cols() + (j+1)))  = 10;
            }
            if( (i < sourceGraph.rows() - 1)  && (sourceGraph(i+1,j) != -1))  // Проверка нижней клетки
            {
                adjacencyMatrix( (i * sourceGraph.cols() + j), ((i+1) * sourceGraph.cols() + j))  = 10;
            }
            if((j > 0) && (sourceGraph(i,j-1) != -1))  // Проверка левой клетки
            {
                adjacencyMatrix( (i * sourceGraph.cols() + j), (i * sourceGraph.cols() + j-1))  = 10;
            }
            if( (i > 0) && (j < sourceGraph.cols() - 1)  && (sourceGraph(i-1,j+1) != -1)) // Проверка верхней правой диагонали
            {
                adjacencyMatrix( (i * sourceGraph.cols() + j), ((i-1) * sourceGraph.cols() + j+1)) = 14;
            }
            if( (i > 0) && (j >0)  && (sourceGraph(i-1,j-1) != -1)) // Проверка верхней левой диагонали
            {
                adjacencyMatrix( (i * sourceGraph.cols() + j), ((i-1) * sourceGraph.cols() + j-1)) = 14;
            }
            if( (i < sourceGraph.rows() - 1) && (j < sourceGraph.cols() - 1)  && (sourceGraph(i+1,j+1) != -1)) // Проверка нижней правой диагонали
            {
                adjacencyMatrix( (i * sourceGraph.cols() + j), ((i+1) * sourceGraph.cols() + j+1)) = 14;
            }
            if( (i < sourceGraph.rows() - 1) && (j >0)  && (sourceGraph(i+1,j-1) != -1)) // Проверка нижней левой диагонали
            {
                adjacencyMatrix( (i * sourceGraph.cols() + j), ((i+1) * sourceGraph.cols() + j-1)) = 14;
            }
        }

    return adjacencyMatrix;
}
