#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "graphs.h"

void floyd(int size, int dist[][size]) {

    int i, j, k;

        for (k = 0; k < size; k++)
        {
            // Parallelize here
            for (i = 0; i < size; i++)
            {
                for (j = 0; j < size; j++)
                {

                    if (dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
}

void printg(int size, int graph[][size]) {
    printf("\n");

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (graph[i][j] == INF) {
                printf("%7s", "INF");
            }
            else {
                printf("%7d", graph[i][j]);
            }
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    int arg = atoi(argv[1]);
    int speed;
    int *graph;

    switch(arg) {
        case 1:
            speed = S1;
            graph = g1;
            break;
        
        case 2:
            speed = S2;
            graph = g2;

        case 3:
            speed = S3;
            graph = g3;
            break;

        case 4:
            speed = S4;
            graph = g4;
            break;

        case 5:
            speed = S5;
            generateGraph(g5);
            graph = g5;
            break;

        default:
            fprintf(stderr, "Bad input");
            exit(64);
        }

    printg(speed, graph);

    // Start Time
    double t1 = omp_get_wtime();
    floyd(speed, graph);
    // End Time
    double t2 = omp_get_wtime();

    printg(speed, graph);

    printf("%f seconds", (t2 - t1));
}