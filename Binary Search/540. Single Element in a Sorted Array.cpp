/*
  Leet code problem :540
Problem name :Single Element in a Sorted Array
Approach:
- Since the array is sorted and every element appears exactly twice except one, we can use Binary Search.
- Find the middle index.
- If the middle element is different from both its adjacent elements, it is the single element.
- Otherwise, use the parity (even/odd index) and the pairing pattern to determine whether the single element lies on the left half or the right half.
- Continue searching until the single element is found.

Time Complexity: O(log n)
Space Complexity: O(1)
  */
class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        int n = A.size();
        int st = 0;
        int end = n - 1;

        if (n == 1)
            return A[0];

        while (st <= end) {
            int mid = st + (end - st) / 2;

            // If the first element is the answer
            if (mid == 0 && A[0] != A[1])
                return A[mid];

            // If the last element is the answer
            if (mid == n - 1 && A[n - 1] == A[n - 2])
                return A[mid];

            // If mid itself is the single element
            if (A[mid] != A[mid - 1] && A[mid] != A[mid + 1]) {
                return A[mid];
            }

            // Binary Search
            if (mid % 2 == 0) { // Even index
                if (A[mid] == A[mid + 1]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else { // Odd index
                if (A[mid] == A[mid - 1]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};
