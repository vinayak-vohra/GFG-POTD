//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
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

public:
    // Function to modify the matrix such that if a matrix cell matrix[i][j]
    // is 1 then all the cells in its ith row and jth column will become 1.
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
};

/* // Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int row, col;
        cin >> row >> col;
        vector<vector<int>> matrix(row);
        for (int i = 0; i < row; i++)
        {
            matrix[i].assign(col, 0);
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        ob.booleanMatrix(matrix);

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

// Driver Code Ends */