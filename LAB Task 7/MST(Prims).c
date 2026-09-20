#include <stdio.h> 
 
#define INF 9999 
#define MAX 100 
 
int main() { 
    int n; 
    int graph[MAX][MAX]; 
    int selected[MAX] = {0}; 
    int i, j, edges = 0; 
    int x, y, min, cost = 0; 
 
    printf("Enter number of vertices: "); 
    scanf("%d", &n); 
 
    printf("Enter adjacency matrix:\n"); 
    for (i = 0; i < n; i++) { 
        for (j = 0; j < n; j++) { 
            scanf("%d", &graph[i][j]); 
 
            if (graph[i][j] == 0) 
                graph[i][j] = INF; 
        } 
    } 
 
    // Start from vertex 0 
    selected[0] = 1; 
 
    printf("\nEdges in MST:\n"); 
 
    while (edges < n - 1) { 
        min = INF; 
 
        for (i = 0; i < n; i++) { 
            if (selected[i]) { 
                for (j = 0; j < n; j++) { 
                    if (!selected[j] && graph[i][j] < min) { 
                        min = graph[i][j]; 
                        x = i; 
                        y = j; 
                    } 
                } 
            } 
        } 
 
        printf("%d - %d : %d\n", x, y, graph[x][y]); 
 
        cost += graph[x][y]; 
        selected[y] = 1; 
        edges++; 
    } 
 
    printf("Minimum Cost = %d\n", cost); 
 
    return 0; 
}

