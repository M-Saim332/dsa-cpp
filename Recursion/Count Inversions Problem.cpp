
/*
Problem: Count Inversions using Merge Sort

Approach:
1. Use the Merge Sort algorithm to divide the array into two halves.
2. Recursively count inversions in the left half.
3. Recursively count inversions in the right half.
4. While merging the two sorted halves:
   - If arr[i] <= arr[j], simply add arr[i] to the temporary array.
   - If arr[i] > arr[j], arr[j] forms an inversion with every
     remaining element in the left half.
   - Therefore, add (mid - i + 1) to the inversion count.
5. Copy the sorted temporary array back into the original array.
6. Return the total number of inversions:
      Left Inversions + Right Inversions + Merge Inversions

Example:
arr = {6, 3, 5, 2, 7}

Inversions:
(6,3), (6,5), (6,2), (3,2), (5,2)

Total Inversions = 5

Time Complexity: O(n log n)
Space Complexity: O(n)

Key Concepts:
- Merge Sort
- Recursion
- Divide and Conquer
- Inversion Counting
- Backtracking through sorted halves
*/



#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& arr, int st, int mid, int end) {

    vector<int> temp;

    int i = st;
    int j = mid + 1;
    int invcount = 0;

    while (i <= mid && j <= end) {

        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
            j++;

            // All remaining elements from i to mid
            // will form an inversion with arr[j]
            invcount += (mid - i + 1);
        }
    }

    // Copy remaining elements from left half
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Copy remaining elements from right half
    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy temp back into original array
    for (int idx = 0; idx < temp.size(); idx++) {
        arr[idx + st] = temp[idx];
    }

    return invcount;
}


int mergesort(vector<int>& arr, int st, int end) {

    if (st < end) {

        int mid = st + (end - st) / 2;

        int leftinvcount = mergesort(arr, st, mid);

        int rightinvcount = mergesort(arr, mid + 1, end);

        int invcount = merge(arr, st, mid, end);

        return leftinvcount + rightinvcount + invcount;
    }

    return 0;
}


int main() {

    vector<int> arr = {6, 3, 5, 2, 7};

    int ans = mergesort(arr, 0, arr.size() - 1);

    cout << "Inversion Count: " << ans << endl;

    return 0;
}

