//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

void updateRow(vector<vector<int>> &matrix, int C, int rowIndex)
{
    for (int j = 0; j < C; j++)
        matrix[rowIndex][j] = 1;
}

void updateCol(vector<vector<int>> &matrix, int R, int colIndex)
{
    for (int i = 0; i < R; i++)
        matrix[i][colIndex] = 1;
}

void booleanMatrix(vector<vector<int>> &matrix)
{
    int R = matrix.size(), C = matrix[0].size();
    vector<bool> rowsToUpdate(R, false);
    vector<bool> colsToUpdate(C, false);

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (matrix[i][j])
            {
                rowsToUpdate[i] = true;
                colsToUpdate[j] = true;
            }

    for (int i = 0; i < R; i++)
        if (rowsToUpdate[i])
            updateRow(matrix, C, i);

    for (int j = 0; j < C; j++)
        if (colsToUpdate[j])
            updateCol(matrix, R, j);
}
