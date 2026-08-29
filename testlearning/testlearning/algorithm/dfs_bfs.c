#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_N 100

void dfsRecursive(int node, int visited[], int graph[][MAX_N], int n) {
    visited[node] = 1;
    printf("%d ", node);
    
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfsRecursive(i, visited, graph, n);
        }
    }
}

void dfsIterative(int start, int graph[][MAX_N], int n) {
    int visited[MAX_N] = {0};
    int stack[MAX_N], top = -1;
    
    stack[++top] = start;
    visited[start] = 1;
    
    while (top >= 0) {
        int node = stack[top--];
        printf("%d ", node);
        
        for (int i = n-1; i >= 0; i--) {
            if (graph[node][i] == 1 && !visited[i]) {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
}

void bfs(int start, int graph[][MAX_N], int n) {
    int visited[MAX_N] = {0};
    int queue[MAX_N], front = 0, rear = 0;
    
    queue[rear++] = start;
    visited[start] = 1;
    
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        
        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int graph[MAX_N][MAX_N] = {0};
    int n = 6;
    
    graph[0][1] = 1; graph[0][2] = 1;
    graph[1][0] = 1; graph[1][3] = 1; graph[1][4] = 1;
    graph[2][0] = 1; graph[2][5] = 1;
    graph[3][1] = 1;
    graph[4][1] = 1; graph[4][5] = 1;
    graph[5][2] = 1; graph[5][4] = 1;
    
    printf("图结构:\n");
    printf("0---1---3\n");
    printf("|   |\n");
    printf("2   4\n");
    printf("|   |\n");
    printf("+---5\n");
    printf("\n");
    
    printf("DFS递归遍历(从0开始): ");
    int visited1[MAX_N] = {0};
    dfsRecursive(0, visited1, graph, n);
    printf("\n");
    
    printf("DFS非递归遍历(从0开始): ");
    dfsIterative(0, graph, n);
    printf("\n");
    
    printf("BFS遍历(从0开始): ");
    bfs(0, graph, n);
    printf("\n");
    
    return 0;
}