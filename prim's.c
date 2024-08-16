#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100
#define INF INT_MAX

int graph[MAX][MAX];

int minKey(int key[], bool mstSet[], int vertices) {
    int min = INF, minIndex;

    for (int v = 0; v < vertices; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], minIndex = v;

    return minIndex;
}

void Prim(int vertices) {
    int parent[MAX];
    int key[MAX];
    bool mstSet[MAX];

    for (int i = 0; i < vertices; i++)
        key[i] = INF, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey(key, mstSet, vertices);
        mstSet[u] = true;

        for (int v = 0; v < vertices; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 1; i < vertices; i++)
        printf("%d -- %d == %d\n", parent[i], i, graph[i][parent[i]]);
}

int main() {
    int vertices;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            scanf("%d", &graph[i][j]);

    Prim(vertices);

    return 0;
}

Enter the number of vertices: 4
Enter the adjacency matrix:
0 2 0 6
2 0 3 8
0 3 0 0
6 8 0 0
