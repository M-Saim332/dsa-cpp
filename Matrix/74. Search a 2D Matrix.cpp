/*
Approach:
1. Use Binary Search on the rows to find the row where the target can exist.
2. For the middle row, check if the target lies between the first and last element.
3. If it does, perform Binary Search on that row.
4. If the target is greater than the last element of the row, search in the lower half.
5. Otherwise, search in the upper half.
6. If the target is found, return true; otherwise, return false.

Time Complexity: O(log m + log n)
Space Complexity: O(1)
*/
class Solution {
public:
    bool searchinrow(vector<vector<int>>& mat, int target, int row) {
        int n = mat[0].size();
        int st = 0, end = n - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (target == mat[row][mid]) {
                return true;
            } else if (target > mat[row][mid]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();

        int sr = 0, er = m - 1;

        while (sr <= er) {
            int mr = sr + (er - sr) / 2;

            if (target >= mat[mr][0] && target <= mat[mr][n - 1]) {
                return searchinrow(mat, target, mr);
            } else if (target > mat[mr][n - 1]) {
                sr = mr + 1;
            } else {
                er = mr - 1;
            }
        }

        return false;
    }
};
