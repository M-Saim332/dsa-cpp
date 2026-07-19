/*
-------------------------------------------------------
Problem 88: Merge Sorted Array

Approach:
- Use three pointers starting from the end of both arrays.
- Compare the last elements of A and B.
- Place the larger element at the end of A.
- Copy any remaining elements of B.

Time Complexity: O(m + n)
Space Complexity: O(1)
-------------------------------------------------------
*/
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {

        int idx = m + n - 1;
        int i = m - 1;
        int j = n - 1;

        while (i >= 0 && j >= 0) {
            if (A[i] > B[j]) {
                A[idx] = A[i];
                i--;
                idx--;
            } else {
                A[idx] = B[j];
                j--;
                idx--;
            }
            
        }

        // Copy remaining elements of B
        while (j >= 0) {
            A[idx] = B[j];
            idx--;
            j--;
        }
    }
};
