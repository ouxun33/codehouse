#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ROW 5
#define COL 5

int maze[ROW][COL] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 1, 0}
};

int visited[ROW][COL] = {0};
int path[ROW*COL][2];
int pathLen = 0;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfsMaze(int x, int y) {
    if (x < 0 || x >= ROW || y < 0 || y >= COL) return 0;
    if (maze[x][y] == 1 || visited[x][y] == 1) return 0;
    if (x == ROW-1 && y == COL-1) {
        path[pathLen][0] = x;
        path[pathLen][1] = y;
        pathLen++;
        return 1;
    }
    
    visited[x][y] = 1;
    path[pathLen][0] = x;
    path[pathLen][1] = y;
    pathLen++;
    
    for (int i = 0; i < 4; i++) {
        if (dfsMaze(x + dx[i], y + dy[i])) {
            return 1;
        }
    }
    
    pathLen--;
    return 0;
}

void printMaze() {
    printf("迷宫地图:\n");
    printf("0=通路, 1=墙壁\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

void printPath() {
    printf("找到的路径:\n");
    for (int i = 0; i < pathLen; i++) {
        printf("(%d, %d)", path[i][0], path[i][1]);
        if (i < pathLen - 1) {
            printf(" -> ");
        }
    }
    printf("\n");
}

int main() {
    printMaze();
    printf("\n");
    
    if (dfsMaze(0, 0)) {
        printPath();
    } else {
        printf("没有找到路径!\n");
    }
    
    return 0;
}