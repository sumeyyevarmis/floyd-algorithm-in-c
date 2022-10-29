// https://oanaunciuleanu.wixsite.com/artofcoding/post/floyd-warshall-algorithm-in-c
#include <stdio.h>
#define V 5
#define INF 9999

void printPath(int pathMatrix[V][V], int x, int y){
    if(pathMatrix[x][y] == x)
        return;
    printPath(pathMatrix, x, pathMatrix[x][y]);
    printf("%d ",pathMatrix[x][y] + 1);
}
void printSolution(int costMatrix[V][V], int pathMatrix[V][V]){
    int x, y;
    printf("Shortest path values matrix: \n");
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(costMatrix[i][j] == INF)
                printf("%7s","INF");
            else
                printf("%7d",costMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
   /* printf("Shortest paths: \n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++){
            if (j != i && pathMatrix[i][j] != -1){
                printf("from vertex %d", i + 1);
                printf(" to vertex %d ", j + 1);
                printf(": %d ", i  + 1);
                printf(" ");
                printPath(pathMatrix, i, j);
                printf(" %d ",j + 1);
                printf("\n");
            }
        }
    }*/
    printf("\n");
    printf("Enter starting point and end point:\n");
    scanf("%d%d",&x,&y);
    x--;
    y--;
    if(y != x && pathMatrix[x][y] != -1){
        printf("from vertex %d", x + 1);
        printf(" to vertex %d ", y + 1);
        printf(": %d ", x  + 1);
        printf(" ");
        printPath(pathMatrix, x, y);
        printf(" %d ",y + 1);
        printf("\n");
    }
    printf("Shortest path values matrix : %d",costMatrix[x][y]);

}
void floyd(int graph[][V]){
    int costMatrix[V][V];
    int pathMatrix[V][V];

    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            costMatrix[i][j] = graph[i][j];
            if(i == j)
                pathMatrix[i][j] = 0;
            else if( costMatrix[i][j] != INF)
                pathMatrix[i][j] = i;
            else
                pathMatrix[i][j] = -1;
        }
    }

    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(costMatrix[i][j] > costMatrix[i][k] + costMatrix[k][j]){
                    costMatrix[i][j] = costMatrix[i][k] + costMatrix[k][j];
                    pathMatrix[i][j] = pathMatrix[k][j];
                }
            }
        }
    }
    printSolution(costMatrix,pathMatrix);
    /*
    printf("All pairs shortest path: \n");
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(graph[i][j] == INF)
                printf("%7s","INF");
            else
                printf("%7d",graph[i][j]);
        }
        printf("\n");
    }
    printf("-------------------------------------\n");
    printf("%d",graph[x][y]);*/
}

int main() {
    // lets create graph

    int graph[V][V] = {
            {0,3,8,INF,-4},
            {INF,0,INF,1,7},
            {INF,4,0,INF,INF},
            {2,INF,-5,0,INF},
            {INF,INF,INF,6,0},
    };
    floyd(graph);
    return 0;
}
