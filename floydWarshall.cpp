///C++ program for Floyd Warshall
#include <bits/stdc++.h>
using namespace std;
#define V  5///no of nodes
#define INF 999

void printSolution(int dist[][V]);

void floydWarshall(int graph[][V])
{
    int dist[V][V], i, j, k;

    ///Initialize the solution matrix as input matrix
    for(i = 0; i < V; i++)
        for(j = 0; j < V; j++)
        dist[i][j] = graph[i][j];

    ///Traverse each pair of nodes
    for(k = 0; k < V; k++) {
        for(i = 0; i< V; i++) {
            for(j = 0; j < V; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    ///Print the solution
    printSolution(dist);
}

void printSolution(int dist[][V])
{
    printf("Shortest distance between every pair of vertices\n");
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            if(dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int graph[V][V]={ {0,3,8,INF,-4},{INF,0,INF,1,7},{INF,4,0,INF,INF},{2,INF,-5,0,INF},{INF,INF,INF,6,0}};
    /*for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }*/
    floydWarshall(graph);
}
