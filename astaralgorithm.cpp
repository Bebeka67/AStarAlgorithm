#include "astaralgorithm.h"

#include <iostream>

AStarAlgorithm::AStarAlgorithm()
{   
}

// перед этой функцией graph должен быть полностью сформирован.


MatrixXi AStarAlgorithm::run(MatrixXi sourceMatrix)
{

    /* с графом должно произойти следующее
     * 1. задаются размеры матрицы
     * 2. инициализироваться состояния клеток (пустая, проходимая, начальная целевая)
    */
    m_graph = new Graph(sourceMatrix);

    QMap<int, Node> NodeMap = createNodeMapFromGraphMatrix(m_graph->graphMatrix());

    Node start = NodeMap.value(m_graph->start());
    Node goal = NodeMap.value(m_graph->goal());

    QList<int> result = A_Star(start, goal, NodeMap);

    if(result.size() == 0)
        return sourceMatrix;

    cout<<"\nresult"<<endl;
    foreach( Node node, result)
    {
        std::cout << node;
    }

    cout << mapThePath(result, *m_graph);

    cout << "\ndone" << endl;
    return mapThePath(result, *m_graph);
}
MatrixXi AStarAlgorithm::mapThePath(QList<int> path, Graph graph)
{
    MatrixXi result;
    result = graph.graphMatrix();

    // i * m_graphMatrix.cols() + j

    for( int i = 0; i < result.rows(); i++ )
        for( int j = 0; j < result.cols(); j++ )
        {
            int index = i * result.cols() + j;
            if( path.contains(index))
            {
                result(i,j) += 5;
            }
        }
    return result;
}



QMap<int, Node> AStarAlgorithm::createNodeMapFromGraphMatrix(MatrixXi matrix)
{
    QMap<int, Node> output;
    for( int row = 0; row < matrix.rows(); row++ )
    {
        for( int col = 0; col < matrix.cols(); col++ )
        {
            Node node = createNodeFromGraph(row, col, matrix);
            output[node.index] = node;
        }
    }
    return output;
}

Node AStarAlgorithm::createNodeFromGraph(int row, int col, MatrixXi matrix)
{
    Node node;
    node.coords = QPair<int,int>(row,col);
    node.index = row * matrix.cols() + col;
    return node;
}

QList<int> AStarAlgorithm::A_Star(Node start, Node goal, QMap<int, Node> map)
{
    QList<Node> openList;
    QList<Node> closedList;

    QMap<int, Node> cameFrom;

    QMap<int, int> gScore;
    gScore[start.index] = 0;

    QMap<int,int> fScore;
    fScore[start.index] = start.h(goal);
    start.fScore = fScore[start.index];


    openList.append(start);

    int counter = 0;
    while (!openList.isEmpty())
    {
        // сортировка списка по возрастанию по полю fScore;


        std::sort( openList.begin(), openList.end() );

        Node current = openList[0];


        if( current.index == goal.index ) // тут идет проверка по индексу
        {
            return reconstructPath(cameFrom, current);
        }


        openList.removeOne(current);
        closedList.append(current);



        current.neighbors = findNeighborsFor(current, *m_graph, map);


        foreach (Node neighbor, current.neighbors) {

            int tentative_gScore = gScore[current.index] + neighbor.costToPrevious;




            if((!gScore.contains(neighbor.index) || tentative_gScore < gScore.value(neighbor.index)) && !closedList.contains(neighbor) )
            {

                gScore[neighbor.index] = tentative_gScore;

                fScore[neighbor.index]  = tentative_gScore + neighbor.h(goal);

                neighbor.fScore = fScore[neighbor.index];
                cameFrom[neighbor.index] = current;

                if (!openList.contains(neighbor))
                {
                    openList.append(neighbor);
                }
            }
        }
    counter++;
    }


    QList<int> err;
    return err;
}

QList<int> AStarAlgorithm::reconstructPath(QMap<int, Node> cameFrom, Node current)
{
    QList<int> totalPath;

    totalPath.append(current.index);

    while( cameFrom.keys().contains(current.index) )
    {
        current = cameFrom.value(current.index);
        totalPath.prepend(current.index);
    }
    return totalPath;
}

QList<Node> AStarAlgorithm::findNeighborsFor(Node node, Graph sourceGraph, QMap<int, Node> map)
{
    QList<Node> result;

    int nodeIndex = node.index;
    for(int j = 0; j < sourceGraph.adjacencyMatrix().cols(); j++)
    {
        if( sourceGraph.adjacencyMatrix()(nodeIndex, j) != 0 )
        {
            Node neighbor = map[j];
            neighbor.costToPrevious = sourceGraph.adjacencyMatrix()(nodeIndex, j);
            result.append(neighbor);
        }
    }
    return result;
}
