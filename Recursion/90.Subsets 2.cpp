/*
Problem No: 90
Problem Name: Subsets II

Approach:
- Use recursion and backtracking to generate all unique subsets from an array with duplicates.
- First, sort `nums` so that identical elements are grouped together.
- For every element, we have two choices:
    1. Include the current element in the subset.
    2. Exclude the current element and skip all its duplicates.
- If we include the element, add it to `ans` and recursively process
  the next element at `i + 1`.
- After returning from the recursive call, use `pop_back()` to undo
  the choice. This is the backtracking step.
- To exclude the current element without generating duplicate subsets, 
  use a `while` loop to skip all adjacent identical elements before making 
  the next recursive call.
- When `i` reaches `nums.size()`, the current subset is complete,
  so add it to `allsubsets`.

Key Pattern:
    Sort → Include → Recursion → Backtrack → Skip Duplicates → Exclude → Recursion

Time Complexity:
    O(n * 2^n)
    Sorting takes O(n log n). There are 2^n possible subsets in the worst case, 
    and copying each subset takes O(n) time.

Space Complexity:
    O(n)
    Auxiliary space used by the recursion stack and the current subset `ans`.
    (Output space is O(n * 2^n).)
*/

class Solution {
public:

    void getallsubsets(
        vector<int>& nums,
        vector<int>& ans,
        int i,
        vector<vector<int>>& allsubsets
    ) {

        // Base Case
        if (i == nums.size()) {
            allsubsets.push_back(ans);
            return;
        }

        // Include the current element
        ans.push_back(nums[i]);
        getallsubsets(nums, ans, i + 1, allsubsets);

        // Backtrack: remove the current element
        ans.pop_back();

        // Exclude: Skip all duplicate elements
        int idx = i + 1;
        while (idx < nums.size() && nums[idx] == nums[i]) {
            idx++;
        }

        // Exclude the current element and jump past its duplicates
        getallsubsets(nums, ans, idx, allsubsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        // Sort to group duplicate values together
        sort(nums.begin(), nums.end());

        vector<vector<int>> allsubsets;
        vector<int> ans;

        getallsubsets(nums, ans, 0, allsubsets);

        return allsubsets;
    }
};
