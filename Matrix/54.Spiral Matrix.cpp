/*
Problem Name:
54. Spiral Matrix

Approach:
- Initialize four boundaries:
  - srow = starting row
  - erow = ending row
  - scol = starting column
  - ecol = ending column
- Traverse the matrix layer by layer in spiral order:
  1. Traverse the top row from left to right.
  2. Traverse the right column from top to bottom.
  3. Traverse the bottom row from right to left (if top and bottom rows are different).
  4. Traverse the left column from bottom to top (if left and right columns are different).
- After completing one layer, move the boundaries inward:
  - srow++, erow--
  - scol++, ecol--
- Repeat until all elements are visited.

Time Complexity: O(n * m)
Space Complexity: O(1) auxiliary space (excluding the output vector)

Key Concepts Used:
- Matrix Traversal
- Boundary Pointers
- Simulation
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int srow = 0;
        int erow = n - 1;
        int scol = 0;
        int ecol = m - 1;

        vector<int> ans;

        while (srow <= erow && scol <= ecol) {

            // Top
            for (int j = scol; j <= ecol; j++) {
                ans.push_back(mat[srow][j]);
            }

            // Right
            for (int i = srow + 1; i <= erow; i++) {
                ans.push_back(mat[i][ecol]);
            }

            // Bottom
            if (srow != erow) {
                for (int j = ecol - 1; j >= scol; j--) {
                    ans.push_back(mat[erow][j]);
                }
            }

            // Left
            if (scol != ecol) {
                for (int i = erow - 1; i >= srow + 1; i--) {
                    ans.push_back(mat[i][scol]);
                }
            }

            srow++;
            erow--;
            scol++;
            ecol--;
        }

        return ans;
    }
};
