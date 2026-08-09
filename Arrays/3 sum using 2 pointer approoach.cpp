/*
Problem Name: 15. 3Sum

Problem Statement:
Find all unique triplets in the array whose sum is equal to 0.

Approach:
- First, sort the array so that we can use the Two-Pointer technique.
- Fix one element using the i pointer.
- Use two pointers:
      j = i + 1
      k = n - 1
- Calculate the sum of nums[i], nums[j], and nums[k].
- If sum > 0, move k left to decrease the sum.
- If sum < 0, move j right to increase the sum.
- If sum == 0, store the triplet and move both pointers.
- Skip duplicate values of i and j to avoid duplicate triplets.

Time Complexity:
O(n²)

Space Complexity:
O(1) excluding the output vector.

Key Concepts Used:
- Sorting
- Two Pointers
- Duplicate Handling
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> ans;

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Fix the first element
        for(int i = 0; i < n; i++) {

            // Skip duplicate i values
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            int j = i + 1;
            int k = n - 1;

            // Step 3: Use two pointers
            while(j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                // Sum is too large
                if(sum > 0) {
                    k--;
                }

                // Sum is too small
                else if(sum < 0) {
                    j++;
                }

                // Sum is exactly 0
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});

                    j++;
                    k--;

                    // Skip duplicate j values
                    while(j < k && nums[j] == nums[j-1])
                        j++;
                }
            }
        }

        return ans;
    }
};
