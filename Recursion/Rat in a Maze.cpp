/*
 * ============================================================================
 * PROBLEM: Rat in a Maze (Backtracking)
 * ============================================================================
 * 
 * APPROACH:
 * 1. Backtracking / Depth-First Search (DFS):
 *    - Start at cell (0, 0) and aim to reach cell (n-1, n-1).
 *    - Recursively explore all four valid moves in order: Down ('D'), Up ('U'),
 *      Left ('L'), and Right ('R').
 * 2. In-Place Visited Tracking:
 *    - Temporarily mark the current cell as `-1` before visiting adjacent 
 *      cells to prevent infinite loops and cyclic paths.
 * 3. Backtracking Step:
 *    - Reset the current cell back to `1` after all adjacent directions have 
 *      been explored, allowing other valid paths to utilize this cell.
 *
 * ----------------------------------------------------------------------------
 * TIME COMPLEXITY: O(3^(N^2))
 * ----------------------------------------------------------------------------
 * - An N x N grid contains N^2 total cells.
 * - From any given cell, up to 4 moves are possible, but because we cannot 
 *   immediately return to the parent cell, the max branching factor is 3.
 * - In the worst case, the path explores every cell, giving a maximum call 
 *   stack depth of N^2.
 * - Upper bound: O(3^(N^2)).
 *
 * ----------------------------------------------------------------------------
 * SPACE COMPLEXITY: O(N^2)
 * ----------------------------------------------------------------------------
 * - Auxiliary Recursion Stack: O(N^2) for the max depth of the call stack.
 * - Memory per Path: O(N^2) max length for the string storing directions.
 * - In-place tracking modifies the matrix directly, using O(1) extra space.
 * - Overall Auxiliary Space (excluding output list `ans`): O(N^2).
 * ============================================================================
 */





#include <iostream>
#include <vector>
#include <string>

using namespace std;

void helper(vector<vector<int>>& mat, int r, int c, int n, string path, vector<string>& ans) {
    // Base case 1: Out of bounds or blocked cell (0 or -1)
    if (r < 0 || c < 0 || r >= n || c >= n || mat[r][c] == 0 || mat[r][c] == -1) {
        return;
    }

    // Base case 2: Reached target cell (n-1, n-1)
    if (r == n - 1 && c == n - 1) {
        ans.push_back(path);
        return;
    }

    // Mark as visited
    mat[r][c] = -1;

    // Down
    helper(mat, r + 1, c, n, path + "D", ans);
    // Up
    helper(mat, r - 1, c, n, path + "U", ans);
    // Left
    helper(mat, r, c - 1, n, path + "L", ans);
    // Right
    helper(mat, r, c + 1, n, path + "R", ans);

    // Backtrack (unvisit)
    mat[r][c] = 1;
}

vector<string> findpath(vector<vector<int>>& mat) {
    vector<string> ans;
    int n = mat.size();

    // Corner case: Starting or ending cell is blocked
    if (n == 0 || mat[0][0] == 0 || mat[n - 1][n - 1] == 0) {
        return ans;
    }

    string path = "";
    helper(mat, 0, 0, n, path, ans);
    return ans;
}

int main() {
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> ans = findpath(mat);

    for (const string& path : ans) {
        cout << path << endl;
    }

    return 0;
}
