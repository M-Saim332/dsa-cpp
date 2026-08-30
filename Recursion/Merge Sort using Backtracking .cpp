/*
 * PROBLEM NAME: Merge Sort Algorithm
 *
 * APPROACH (Divide and Conquer):
 * 1. Divide: Split the array into two equal halves recursively until individual 
 *    elements or empty subarrays remain (base case: size <= 1).
 * 2. Conquer: Recursively process and sort the left and right subarrays.
 * 3. Combine (Merge): Compare elements from both sorted halves sequentially 
 *    using a two-pointer approach, merge them into a temporary vector in 
 *    sorted order, and copy the result back into the original array space.
 *
 * TIME COMPLEXITY:
 * - Best Case:  O(N log N) - Array is already sorted; tree depth is log N.
 * - Avg Case:   O(N log N) - Standard recursive partitioning behavior.
 * - Worst Case: O(N log N) - Every element is processed across all log N levels.
 *
 * SPACE COMPLEXITY:
 * - Auxiliary Space: O(N) due to the temporary vector used in the merge step.
 * - Call Stack Space: O(log N) recursion depth.
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 * FUNCTION: merge
 * PURPOSE: Combines two adjacent sorted subarrays [st...mid] and [mid+1...end]
 *          into a single sorted sequence in-place using a temporary buffer.
 */
void merge(vector<int>& arr, int st, int mid, int end) {
    vector<int> temp;
    int i = st;       // Pointer for left sorted subarray
    int j = mid + 1;  // Pointer for right sorted subarray

    /*
     * Compare elements from both halves and insert the smaller 
     * element into the temporary buffer until one half is exhausted.
     */
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    /*
     * Copy any remaining elements from the left subarray (if any).
     */
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    /*
     * Copy any remaining elements from the right subarray (if any).
     */
    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    /*
     * Overwrite original array positions [st...end] with sorted values from temp.
     */
    for (int idx = 0; idx < temp.size(); idx++) {
        arr[idx + st] = temp[idx];
    }
}

/*
 * FUNCTION: mergesort
 * PURPOSE: Recursively divides the array into subproblems and sorts them.
 */
void mergesort(vector<int>& arr, int st, int end) {
    // Base Case: If sub-array has 1 or 0 elements, it is already sorted.
    if (st < end) {
        // Calculate mid using overflow-safe formula
        int mid = st + (end - st) / 2;

        // Step 1: Recursively sort left subarray
        mergesort(arr, st, mid);

        // Step 2: Recursively sort right subarray
        mergesort(arr, mid + 1, end);

        // Step 3: Merge the two sorted halves back together
        merge(arr, st, mid, end);
    }
}

int main() {
    vector<int> arr = {12, 31, 35, 8, 32, 17};

    // Execute Merge Sort across full range [0 ... N-1]
    mergesort(arr, 0, arr.size() - 1);

    // Output the sorted elements
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
