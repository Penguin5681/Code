#include <bits/stdc++.h>

bool isSafe(int **Array1, int x, int y, int n) {

    if (x < n and y < n and Array1[x][y] == 1) {
        return true;
    }
    return false;
}

bool RatInAMaze(int **Array1, int x, int y, int n, int **SolArray) {
    
    if (x == n - 1 and y == n - 1) {
        SolArray[x][y] = 1;
        return true;
    }

    if (isSafe(Array1, x, y, n)) {
        SolArray[x][y] = 1;
        if(RatInAMaze(Array1, x + 1, y, n ,SolArray)) {
            return true;
        }
        if (RatInAMaze(Array1, x, y + 1, n , SolArray)) {
            return true;
        }
        // Backtrack
        SolArray[x][y] = 0;
        return false;
    }
    return false;
}

signed main(void) {

    int n; std::cin >> n;

    int **Array1 = new int*[n];

    for (int i = 0; i < n; i++) {
        Array1[i] = new int[n];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> Array1[i][j];
        }
    }

    int **SolArray = new int*[n];
    for (int i = 0; i < n; i++) {
        SolArray[i] = new int[n];
        for (int j = 0; j < n; j++) {
            SolArray[i][j] = 0;
        }
    }
    
    if (RatInAMaze(Array1, 0, 0, n, SolArray)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << SolArray[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
}
/* 
1 0 1 0 1
1 1 1 1 1
0 1 0 1 0
1 0 0 1 1
1 1 1 0 1
*/
