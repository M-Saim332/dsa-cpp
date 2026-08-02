/*
Problem Name:
Matrix Diagonal Sum

Problem Statement:
Given a square matrix, return the sum of its primary and secondary diagonals.
If the center element belongs to both diagonals, count it only once.

Approach:
- Traverse the matrix using a single loop.
- Add the primary diagonal element (mat[i][i]).
- Add the secondary diagonal element (mat[i][n-i-1]).
- If both diagonals meet at the center, add that element only once.
- Return the total diagonal sum.

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Concepts Used:
- 2D Matrix Traversal
- Diagonal Traversal
- Conditional Check
*/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += mat[i][i];  // Primary diagonal

            if (i != n - i - 1) {
                sum += mat[i][n - i - 1];  // Secondary diagonal
            }
        }
        return sum;
    }
};

