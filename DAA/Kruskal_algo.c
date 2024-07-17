#include <stdio.h>
#include <stdlib.h>
int comparator(const void *a, const void *b) {
    const int (*edge1)[3] = a;
    const int (*edge2)[3] = b;
    return (*edge1)[2] - (*edge2)[2];
}
void makeSet(int parent[], int rank[], int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int parent[], int node) {
    if (parent[node] != node) {
        parent[node] = findParent(parent, parent[node]);
    }
    return parent[node];
}

// Unite two sets by rank
void unionSets(int u, int v, int parent[], int rank[]) {
    int rootU = findParent(parent, u);
    int rootV = findParent(parent, v);

    if (rank[rootU] < rank[rootV]) {
        parent[rootU] = rootV;
    } else if (rank[rootU] > rank[rootV]) {
        parent[rootV] = rootU;
    } else {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
}

// Kruskal's algorithm to find the Minimum Spanning Tree (MST)
void kruskalAlgorithm(int numEdges, int edges[][3], int numVertices) {
    // Sort edges by weight
    qsort(edges, numEdges, sizeof(edges[0]), comparator);

    int parent[numVertices];
    int rank[numVertices];

    // Initialize parent and rank arrays
    makeSet(parent, rank, numVertices);

    int minCost = 0;
    printf("Edges in the Minimum Spanning Tree:\n");

    for (int i = 0; i < numEdges; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        int rootU = findParent(parent, u);
        int rootV = findParent(parent, v);

        // If u and v are in different sets, include this edge in the MST
        if (rootU != rootV) {
            unionSets(u, v, parent, rank);
            minCost += weight;
            printf("%d -- %d == %d\n", u, v, weight);
        }
    }

    printf("Minimum Cost of Spanning Tree: %d\n", minCost);
}

// Driver code
int main() {
    int numVertices, numEdges;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    int edges[numEdges][3];

    printf("Enter the edges in the format (u v weight):\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    kruskalAlgorithm(numEdges, edges, numVertices);

    return 0;
}
