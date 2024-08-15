#include <stdio.h>
#include <stdlib.h>

int main () {
    int pointsSize = 4;  // Number of points
    int pointsColSize = 2;  // Each point has 2 coordinates
    
    // 2D array of points
    int points[4][2] = {
        {0, 0},
        {0, 6},
        {0, 3},
        {1, 0}
    };
    
    // Convert to int** to match the function signature
    int* pointsPtr[4] = { points[0], points[1], points[2], points[3] };
    
    int result = numberOfPairs(pointsPtr, pointsSize, &pointsColSize);
    printf("%d", result);

    return 0;
}



int numberOfPairs(int** points, int pointsSize, int* pointsColSize) {
    int count = 0;
    if (pointsSize<3) {
        if (minimumPoints(points, pointsSize)==1) {
            return 1;
        }
    }
    int valid;
    for (int i = 0; i < pointsSize; i++) {
        for (int j = i+1; j < pointsSize; j++) {
            valid = 1;
            if (points[i][0]<=points[j][0] && points[i][1]>=points[j][1]) {
                for (int a = 0; a < pointsSize; a++) {
                    if (points[a][0]>=points[i][0] && points[a][0]<=points[j][0] && 
                          points[a][1]<=points[i][1] && points[a][1]>=points[j][1] && a != i && a != j) {
                        valid = 0;
                        break;
                    }
                }
            } else if (points[i][0]>=points[j][0] && points[i][1]<=points[j][1]) {
                for (int a = 0; a < pointsSize; a++) {
                    if (points[a][0]<=points[i][0] && points[a][0]>=points[j][0] && 
                          points[a][1]>=points[i][1] && points[a][1]<=points[j][1] && a != i && a != j) {
                        valid = 0;
                        break;
                    }
                }
            } else {
                valid = 0;
            }
            if (valid) {
                printf("(%d,%d) and (%d,%d), ", points[i][0], points[i][1], points[j][0], points[j][1]);
                count++;
            }
        }
    }
    return count;
}

int minimumPoints(int** points, int pointsSize) {
    if (pointsSize < 2) {
        return 0;
    }
    if ((points[0][0]<=points[1][0] && points[0][1]>=points[1][1]) || (points[0][0]>=points[1][0] && points[0][1]<=points[1][1])) {
        return 1;
    } else {
        return 0;
    }
}