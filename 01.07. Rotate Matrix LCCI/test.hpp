#include "bits/stdc++.h"
#include "../include/helper.hpp"
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        auto tmp = matrix;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = tmp[n - 1 - j][i];
            }
        }
    }
};

class Solution_2 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        auto tmp = matrix;
        for (int row = 0; row < n / 2; row++) {
            for (int col = 0; col < (n + 1) / 2; col++) {
                int tmp = matrix[n-col-1][row];
                matrix[n-col-1][row] = matrix[n-row-1][n-col-1];
                matrix[n-row-1][n-col-1] = matrix[col][n-row-1];
                matrix[col][n-row-1] = matrix[row][col];
                matrix[row][col] = tmp;
            }
        }
    }
};

/*
1 2 3
4 5 6
7 8 9

7 4 1
8 5 2
9 6 3


m[row][col] = m[n-col-1][row]


tmp = m[row][col]
m[row][col] = m[n-col-1][row]   (0,0) = (2,0)

n-col-1=row
row=col

tmp = m[col][n-row-1]
m[col][n-row-1] = m[row][col]   (0,2) = (0,0)

n-col-1=col
row=n-row-1

tmp = m[n-row-1][n-col-1]
m[n-row-1][n-col-1] = m[col][n-row-1]   (2,2) = (0,2)

n-col-1=n-row-1
row=n-col-1

tmp = m[n-col-1][row]
m[n-col-1][row] = m[n-row-1][n-col-1]   (2,0) = (2,2)

=>

tmp = m[n-col-1][row]
m[n-col-1][row] = m[n-row-1][n-col-1]
m[n-row-1][n-col-1] = m[col][n-row-1]
m[col][n-row-1] = m[row][col]
m[row][col] = tmp
*/