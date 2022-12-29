/*
    Author: @thechillguy69
    Created on: 29/12/2022 16:02
*/

#include <bits/stdc++.h>

bool isSafe(int **Array, int x, int y, int n) {

    for (int row = 0; row < x; row++) {
        if (Array[row][y] == 1) {
            return false;
        }
    }
    int row = x; int col = y;
        while (row >= 0 and col >= 0) {
            if (Array[row][col] == 1) {
                return false;
            }
            row--; col--;
        }
        
    row = x; col = y;
        while (row >= 0 and col < n) {
            if (Array[row][col] == 1) {
                return false;
            }
            row--; col++;
        }
        return true;
}

//Backtrack

bool NQueen(int **Array, int x, int n) {

    if (x >= n) {
        return true;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(Array, x, col, n)) {
            Array[x][col] = 1;
            if (NQueen(Array, x + 1, n)) {
                return true;
            }
            Array[x][col] = 0; // Backtracking Step ;)
        }
    }
    return false;
}

signed main(void) {
    int N;
    std::cin >> N;
    
    int **Array = new int*[N];
        for (int i = 0; i < N; i++) {
            Array[i] = new int[N];
                for (int j = 0; j < N; j++) {
                    Array[i][j] = 0;
                }
        }

    if (NQueen(Array, 0, N)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cout << Array[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
}
