/*
Problem no:240 ( Search a 2D Matrix II)
Approach:
1. Start from the top-right corner of the matrix.
2. If the current element equals the target, return true.
3. If the current element is greater than the target, move left.
4. If the current element is smaller than the target, move down.
5. Repeat until the target is found or you go out of the matrix.
6. If the search ends without finding the target, return false.

Time Complexity: O(m + n)
Space Complexity: O(1)
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m=mat.size(),n=mat[0].size();
        int r=0 ,c=n-1;
        while(r<m && c>=0){
            int mid= r + (r-c)/2;
            if (target==mat[r][c]){
                return true;

            }else if(target<mat[r][c]){// Current element is too large, move left
                c--;
            }else{ // Current element is too small, move down
                r++;
            }
        }
        return false;
        
    }
};
