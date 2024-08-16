#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

struct Edge edges[MAX];
struct Edge result[MAX];
struct Subset subsets[MAX];

int find(int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets[i].parent);
    return subsets[i].parent;
}

void Union(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

int compare(const void *a, const void *b) {
    struct Edge *edgeA = (struct Edge *)a;
    struct Edge *edgeB = (struct Edge *)b;
    return edgeA->weight > edgeB->weight;
}

void Kruskal(int vertices, int edgesCount) {
    int i, e = 0, resultIndex = 0;

    qsort(edges, edgesCount, sizeof(edges[0]), compare);

    for (i = 0; i < vertices; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    i = 0;
    while (resultIndex < vertices - 1 && i < edgesCount) {
        struct Edge nextEdge = edges[i++];

        int x = find(nextEdge.u);
        int y = find(nextEdge.v);

        if (x != y) {
            result[resultIndex++] = nextEdge;
            Union(x, y);
        }
    }

    printf("Edges in the Minimum Spanning Tree:\n");
    for (i = 0; i < resultIndex; i++)
        printf("%d -- %d == %d\n", result[i].u, result[i].v, result[i].weight);
}

int main() {
    int vertices, edgesCount;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edgesCount);

    for (int i = 0; i < edgesCount; i++) {
        printf("Enter edge %d (u v weight): ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    Kruskal(vertices, edgesCount);

    return 0;
}

Enter the number of vertices: 4
Enter the number of edges: 5
Enter edge 1 (u v weight): 0 1 10
Enter edge 2 (u v weight): 0 2 6
Enter edge 3 (u v weight): 0 3 5
Enter edge 4 (u v weight): 1 3 15
Enter edge 5 (u v weight): 2 3 4
