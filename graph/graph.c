#include <stdio.h>
#define MAX_SIZE 100

void addEdge(int graph[][MAX_SIZE], int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void printGraph(int graph[][MAX_SIZE], int vertexCount)
{
    for (int i = 0; i < vertexCount; i++)
    {
        printf("Node %d is connected to: ", i);
        for (int j = 0; j < vertexCount; j++)
        {
            if (graph[i][j] == 1)
            {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

void bfs(int startVertex, int graph[][MAX_SIZE], int visited[MAX_SIZE], int vertexCount)
{
    int queue[MAX_SIZE], front = -1, rear = -1, vertex;
    queue[++rear] = startVertex;
    visited[startVertex] = 1;
    printf("BFS Traversal: ");
    printf("%d ", startVertex);
    while (front != rear)
    {
        vertex = queue[++front];
        for (int i = 0; i < vertexCount; i++)
        {
            if (graph[vertex][i] && !visited[i])
            {
                queue[++rear] = i;
                visited[i] = 1;
                printf("%d ", i);
            }
        }
    }
    printf("\n");
}
void dfs(int graph[][MAX_SIZE], int visited[MAX_SIZE], int vertex, int vertexCount)
{
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < vertexCount; i++)
    {
        if (graph[vertex][i] && !visited[i])
        {
            dfs(graph, visited, i, vertexCount);
        }
    }
}
int main()
{
    int graph[MAX_SIZE][MAX_SIZE] = {0};
    // Add edges to make the graph branched
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 6);
    addEdge(graph, 4, 6);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 7);
    addEdge(graph, 6, 7);
    addEdge(graph, 6, 8);
    printGraph(graph, 9);
    int visited[MAX_SIZE] = {0};
    dfs(graph, visited, 0, 9);
    return 0;
}
