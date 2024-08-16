#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100
#define INF INT_MAX

int graph[MAX][MAX];

int minDistance(int dist[], bool sptSet[], int vertices) {
    int min = INF, minIndex;

    for (int v = 0; v < vertices; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], minIndex = v;

    return minIndex;
}

void Dijkstra(int vertices, int src) {
    int dist[MAX];
    bool sptSet[MAX];

    for (int i = 0; i < vertices; i++)
        dist[i] = INF, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minDistance(dist, sptSet, vertices);

        sptSet[u] = true;

        for (int v = 0; v < vertices; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < vertices; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    int vertices, src;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix (use %d to represent infinity):\n", INF);
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    Dijkstra(vertices, src);

    return 0;
}

Enter the number of vertices: 5
Enter the adjacency matrix (use 2147483647 to represent infinity):
0 10 2147483647 30 100
10 0 50 2147483647 2147483647
2147483647 50 0 20 10
30 2147483647 20 0 60
100 2147483647 10 60 0
Enter the source vertex: 0
