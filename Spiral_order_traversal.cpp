// This code prints a 2D Array in a spiral order

#include <bits/stdc++.h>

signed main(void) {
    int N, M;
    std::cin >> N >> M;

    int Array[N][M];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> Array[i][j];
        }
    }
    // Spiral Order Logic
    int row_start = 0;
    int row_end = N - 1;
    int column_start = 0;
    int column_end = M - 1;

        while (row_start <= row_end and column_start <= column_end) {
            // For Row start
            for (int col = column_start; col <= column_end; col++) {
                std::cout << Array[row_start][col] << " ";
            }
            row_start++;
            // For column end
            for (int row = row_start; row <= row_end; row++) {
                std::cout << Array[row][column_end] << " ";
            }
            column_end--;
            // For row end
            for (int col = column_end; col >= column_start; col--) {
                std::cout << Array[row_end][col] << " ";
            }
            row_end--;
            // For Column start
            for (int row = row_end; row >= row_start; row--) {
                std::cout << Array[row][column_start] << " ";
            }
            column_start++;
        }
        return 0;
}