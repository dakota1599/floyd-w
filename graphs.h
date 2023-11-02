#include <math.h>

#define S1 6
#define S2 4
#define S3 10
#define S4 30
#define S5 100
#define INF 99999

int g1[S1][S1] = {
    // 0
    {0, 2, INF, INF, INF, INF},
    // 1
    {INF, 0, 5, 2, INF, INF},
    // 2
    {INF, INF, 0, 3, INF, INF},
    // 3
    {INF, INF, INF, 0, 6, INF},
    // 4
    {INF, INF, INF, INF, 0, 2},
    // 5
    {4, INF, INF, INF, INF, 0}
};

int g2[S2][S2] = { 
    // 0
    { 0, 5, INF, 10 },
    // 1
    { INF, 0, 3, INF },
    // 2
    { INF, INF, 0, 1 },
    // 3
    { INF, INF, INF, 0 } 
};

int g3[S3][S3] = {
    {0, 2, INF, INF, INF, INF, INF, INF, INF, INF},
    {INF, 0, 3, 4, INF, INF, INF, INF, INF, INF},
    {INF, INF, 0, INF, 6, INF, INF, INF, INF, INF},
    {INF, INF, INF, 0, 4, INF, INF, INF, INF, INF},
    {INF, INF, INF, INF, 0, 7, INF, INF, INF, INF},
    {INF, INF, 2, 2, INF, 0, 10, INF, INF, INF},
    {INF, INF, INF, INF, INF, INF, 0, 1, 3, INF},
    {INF, INF, INF, INF, INF, INF, INF, 0, INF, INF},
    {INF, INF, INF, INF, INF, INF, INF, INF, 0, 3},
    {10, INF, INF, INF, INF, INF, INF, INF, INF, 0}
};

int g4[S4][S4] = {
    // 0
    {0, 1, 2, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    // 1
    {INF, 0, INF, 2, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    // 2
    {INF, INF, 0, 2, 4, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    // 3
    {INF, INF, INF, 0, 7, INF, 2, 2, 20, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    // 4
    {INF, INF, INF, INF, 0, 3, INF, INF, 10, 6, INF, 3, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    // 5
    {4, INF, INF, INF, INF, 0, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    // 6
    {INF, INF, INF, INF, INF, INF, 0, INF, INF, INF, INF, INF, INF, 3, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    // 7
    {INF, INF, INF, INF, INF, INF, 1, 0, 1, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    // 8
    {INF, INF, INF, INF, INF, INF, INF, INF, 0, 5, INF, INF, INF, INF, 2, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    // 9
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, 3, INF, INF, INF, INF, INF, 4, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    // 10
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, 2, INF, INF, INF, INF, INF, INF, 4, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    // 11
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, 1, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    // 12
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF, INF, INF, INF, INF, INF, 3, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    // 13
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF, INF, INF, INF, INF, INF, INF, INF, 1, INF, INF, INF, INF, INF, INF},
    // 14
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 5, INF, INF, INF, INF},
    // 15
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF, INF, INF, INF, INF, INF, 5, INF, INF, INF, INF, INF, INF},
    // 16
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF, INF, INF, INF, INF, INF, INF, 5, INF, INF, INF, INF},
    // 17
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF, INF, INF, INF, INF, INF, 5, INF, INF, INF, INF},
    // 18
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF, INF, INF, INF, 6, 5, INF, INF, INF, INF},
    // 19
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, 2, 9, INF, INF, INF, INF, INF, INF, INF, INF},
    // 20
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 7, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF, INF, INF, INF, INF, INF, INF, INF},
    // 21
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF, INF, 5, INF, INF, INF, INF},
    // 22
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF, INF, INF, INF, 2, INF},
    // 23
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF, INF, INF, INF, INF},
    // 24
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 4, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF, INF, INF, 6},
    // 25
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 5, INF, 5, 5, 5, INF, INF, 5, INF, INF, INF, 0, INF, INF, INF, INF},
    // 26
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 1, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF, INF},
    // 27
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 3, 0, INF, INF},
    // 28
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 3, INF, INF, INF, 0, INF},
    // 29
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 3, INF, 0},

};

int g5[S5][S5] = {0};

void generateGraph(int g[][S5]) {
    for (int i = 0; i < S5; i++) {
        for (int j = 0; j < S5; j++) {
            if (i == j) {
                g[i][j] = 0;
            }
            else {
                g[i][j] = rand() % 20 + 1;
            }
        }
    }
}