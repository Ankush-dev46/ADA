#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void push(int vertex) {
    stack[++top] = vertex;
}

int pop() {
    return stack[top--];
}

void DFS(int v, int vertices) {
    visited[v] = 1;

    for (int i = 0; i < vertices; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            DFS(i, vertices);
        }
    }

    push(v);
}

void topologicalSort(int vertices) {
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;

    for (int i = 0; i < vertices; i++)
        if (!visited[i])
            DFS(i, vertices);

    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", pop());
    }
    printf("\n");
}

int main() {
    int vertices, edges, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            graph[i][j] = 0;

    printf("Enter the edges (u v) where u -> v:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    topologicalSort(vertices);

    return 0;
}

Enter the number of vertices: 6
Enter the number of edges: 6
Enter the edges (u v) where u -> v:
5 2
5 0
4 0
4 1
2 3
3 1
