/*
-------------------------------------------------------
Problem 31: Next Permutation

Approach:
- Find the first index from the right where A[i] < A[i+1] (pivot).
- If no pivot exists, reverse the entire array.
- Otherwise, find the first greater element from the right,
  swap it with the pivot, then reverse the suffix.

Time Complexity: O(n)
Space Complexity: O(1)
-------------------------------------------------------
*/
class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int n = A.size();
        int piv = -1;

        // Find the pivot
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] < A[i + 1]) {
                piv = i;
                break;
            }
        }

        // If no pivot exists, reverse the entire array
        if (piv == -1) {
            reverse(A.begin(), A.end());
            return;
        }

        // Find the next greater element from the right
        for (int i = n - 1; i > piv; i--) {
            if (A[i] > A[piv]) {
                swap(A[i], A[piv]);
                break;
            }
        }

        // Reverse the suffix
        int i = piv + 1, j = n - 1;
        while (i < j) {
            swap(A[i], A[j]);
            i++;
            j--;
        }
    }
};
// Method 2 using the Stl function

class Solution {
public:
    void nextPermutation(vector<int>& A) {
      next_permutation(A.begin(),A.end());
    }
}



