/*
Problem No: 78
Problem Name: Subsets

Approach:
- Use recursion and backtracking to generate all possible subsets.
- For every element, we have two choices:
    1. Include the current element in the subset.
    2. Exclude the current element from the subset.
- If we include the element, add it to `ans` and recursively process
  the next element.
- After returning from the recursive call, use `pop_back()` to undo
  the choice. This is the backtracking step.
- Then, exclude the current element and recursively process the next
  element without adding it to `ans`.
- When `i` reaches `nums.size()`, the current subset is complete,
  so add it to `allsubsets`.

Key Pattern:
    Include → Recursion → Backtrack → Exclude → Recursion

Time Complexity:
    O(n * 2^n)
    There are 2^n possible subsets, and copying each subset can take O(n).

Space Complexity:
    O(n)
    Auxiliary space used by recursion and the current subset.
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

        // Exclude the current element
        getallsubsets(nums, ans, i + 1, allsubsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> allsubsets;
        vector<int> ans;

        getallsubsets(nums, ans, 0, allsubsets);

        return allsubsets;
    }
};
