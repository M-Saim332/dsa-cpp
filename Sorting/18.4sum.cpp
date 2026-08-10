
/*
    Problem Name: 4Sum

    Problem Statement:
    Given an integer array nums and an integer target, find all unique
    quadruplets [a, b, c, d] such that:

        a + b + c + d = target

    Each quadruplet should contain different indices, and duplicate
    quadruplets should not be included.

    Approach:
    1. First, sort the array. This helps us handle duplicates and
       allows us to use the two-pointer technique.

    2. Use two nested loops:
       - i selects the first element.
       - j selects the second element.

    3. For every pair (i, j), use two pointers:
       - p starts from j + 1.
       - q starts from the last index.

    4. Calculate the sum of nums[i], nums[j], nums[p], and nums[q].

       - If sum < target:
            Move p forward because we need a larger sum.

       - If sum > target:
            Move q backward because we need a smaller sum.

       - If sum == target:
            Store the quadruplet and move both pointers.

    5. Skip duplicate values for i, j, p, and q so that the answer
       contains only unique quadruplets.

    6. long long is used for calculating the sum to prevent integer
       overflow when the numbers are large.

    Time Complexity:
    O(n^3)

    Space Complexity:
    O(1) extra space
    (excluding the space required to store the answer)

    Key Concepts Used:
    - Sorting
    - Nested Loops
    - Two Pointer Technique
    - Duplicate Handling
    - Long Long for Overflow Prevention
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            // Skip duplicates for i
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n; j++) {
                // Skip duplicates for j
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int p = j + 1, q = n - 1;

                while (p < q) {
                    long long sum = (long long)nums[i] + (long long)nums[j]
                                  + (long long)nums[p] + (long long)nums[q];

                    if (sum < target) {
                        p++;
                    } else if (sum > target) {
                        q--;
                    } else { // sum == target
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++; 
                        q--;

                        // Skip duplicates for p and q
                        while (p < q && nums[p] == nums[p - 1]) p++;
                        while (p < q && nums[q] == nums[q + 1]) q--;
                    }
                }
            }
        }

        return ans;
    }
};
