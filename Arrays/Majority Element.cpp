/*
Problem: Majority Element
Platform: LeetCode
Problem No: 169
Difficulty: Easy

Approach:
Use Moore's Voting Algorithm to find the majority element by maintaining
a candidate and its count. Since the majority element appears more than
n/2 times, it remains as the final candidate.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return nums[n/2];

    }
};
