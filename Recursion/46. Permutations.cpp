/*
 * ============================================================================
 * Problem: 46. Permutations
 * Platform: LeetCode
 * URL: https://leetcode.com/problems/permutations/
 * Language: C++
 * ============================================================================
 * 
 * APPROACH: Backtracking (In-Place Swapping)
 * - Use a decision tree depth-first search (DFS) pattern.
 * - At each index 'idx', iterate through all elements from 'idx' to the end.
 * - Swap the element at 'idx' with the current element 'i' to fix it in position.
 * - Recursively explore further positions with 'idx + 1'.
 * - Backtrack by undoing the swap to restore the array state for other branches.
 * 
 * COMPLEXITY:
 * - Time Complexity: O(N * N!)
 *   - There are N! total permutations generated.
 *   - Copying each valid vector into the answer array takes O(N) time.
 * - Space Complexity: O(N)
 *   - Auxiliary space is driven by the maximum recursion tree depth of N.
 * ============================================================================
 */
class Solution {
public:
    void getperm(vector<int>& nums, int idx, vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        // Start swapping from the current index (idx) to avoid redundant permutations
        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            getperm(nums, idx + 1, ans);
            // Backtrack: restore original order
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getperm(nums, 0, ans);
        return ans;
    }
};
