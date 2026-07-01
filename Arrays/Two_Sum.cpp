/*
Problem: Two Sum
Platform: LeetCode
Problem No: 1
Difficulty: Easy

Approach:
- Hash Map

Time Complexity: O(n^2)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

       
    int n = nums.size();
    vector<int> ans;

    // Brute Force Approach
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }

    
    return {};
}
    
};
