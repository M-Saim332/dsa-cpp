```cpp
/*
    Problem:
    --------
    Sort an array containing only 0s, 1s, and 2s in-place.

    Approach: Dutch National Flag Algorithm
    Time Compelxity:O(n)
    ---------------------------------------
    We use three pointers:

    1. low  -> Points to the position where the next 0 should be placed.
    2. mid  -> Traverses the array.
    3. high -> Points to the position where the next 2 should be placed.

    Initially:
        low = 0
        mid = 0
        high = n - 1

    Cases:
    ------

    1. If nums[mid] == 0
       - Swap nums[low] and nums[mid].
       - Increment both low and mid.
       Reason:
       The 0 is placed in its correct position.

    2. If nums[mid] == 1
       - Simply increment mid.
       Reason:
       1 is already in the correct middle section.

    3. If nums[mid] == 2
       - Swap nums[mid] and nums[high].
       - Decrement high.
       - Do NOT increment mid because the new element
         at mid has not been processed yet.

    Continue until mid > high.

    Time Complexity : O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {

        // Initialize the three pointers
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        // Process elements until mid crosses high
        while (mid <= high) {

            // Current element is 0
            if (nums[mid] == 0) {

                // Place 0 at the beginning
                swap(nums[low], nums[mid]);

                low++;
                mid++;
            }

            // Current element is 1
            else if (nums[mid] == 1) {

                // 1 is already in the correct section
                mid++;
            }

            // Current element is 2
            else {

                // Move 2 to the end
                swap(nums[mid], nums[high]);

                high--;

                // Do not increment mid here because
                // the swapped element needs to be checked.
            }
        }
    }
};

