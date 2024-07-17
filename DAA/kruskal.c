#include <stdio.h>
#include <stdlib.h>

int comparator(const void *a, const void *b)
{   const int(*edge1)[3] = a;
    const int(*edge2)[3] = b;
    return (*edge1)[2] - (*edge2)[2];
}

void makeSet(int parent[], int rank[], int n)
{   for (int i = 0; i < n; i++)
    {   parent[i] = i;
        rank[i] = 0;    }
}
int findParent(int parent[], int node)
{   if (parent[node] != node)
        parent[node] = findParent(parent, parent[node]);
    return parent[node];
}
void unionSets(int u, int v, int parent[], int rank[])
{   int rootU = findParent(parent, u);
    int rootV = findParent(parent, v);
    if (rank[rootU] < rank[rootV])
        parent[rootU] = rootV;
    else if (rank[rootU] > rank[rootV])
        parent[rootV] = rootU;
    else
    {   parent[rootV] = rootU;
        rank[rootU]++;    }
}
void kruskalAlgorithm(int numEdges, int edges[][3], int numVertices)
{    qsort(edges, numEdges, sizeof(edges[0]), comparator);
    int parent[numVertices];
    int rank[numVertices];
    makeSet(parent, rank, numVertices);
    int minCost = 0;
    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < numEdges; i++)
    {   int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        int rootU = findParent(parent, u);
        int rootV = findParent(parent, v);
        if (rootU != rootV)
        {   unionSets(u, v, parent, rank);
            minCost += weight;
            printf("%d --- %d == %d\n", u, v, weight);        }
    }
    printf("Minimum Cost of Spanning Tree: %d\n", minCost);
}
// int main()
// {   int edges[7][3] = {
//         {0, 1, 7},
//         {0, 3, 5},
//         {1, 2, 8},
//         {1, 3, 9},
//         {1, 4, 7},
//         {2, 4, 5},
//         {3, 4, 15}};
//     int numVertices = 5;
//     int numEdges = 7;
//     kruskalAlgorithm(numEdges, edges, numVertices);
//     return 0;
// }

int main()
{   int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    int edges[numEdges][3];
    printf("Enter the edges in the format (u v weight):\n");
    for (int i = 0; i < numEdges; i++) 
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    kruskalAlgorithm(numEdges, edges, numVertices);
    return 0;
}