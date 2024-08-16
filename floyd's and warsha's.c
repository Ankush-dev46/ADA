#include <stdio.h>
#define MAX 100
#define INF 99999

int graph[MAX][MAX];

void FloydWarshall(int vertices) {
    int dist[MAX][MAX];

    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < vertices; k++) {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix (use %d to represent infinity):\n", INF);
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            scanf("%d", &graph[i][j]);

    FloydWarshall(vertices);

    return 0;
}

Enter the number of vertices: 4
Enter the adjacency matrix (use 99999 to represent infinity):
0 3 99999 7
8 0 2 99999
5 99999 0 1
2 99999 99999 0
