/*
Problem: Maximum Subarray
Platform: LeetCode
Problem No: 53
Difficulty: Medium

Approach: Kadane's Algorithm

Time Complexity: O(n)
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int CS=0;
        int MS=INT_MIN;
        for (int i=0;i<nums.size();i++){
            CS+=nums[i];
            MS=max(CS,MS);
            if (CS<0){
                CS=0;
            }
        }
        return MS;
        
    }
};class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int CS=0;
        int MS=INT_MIN;
        for (int i=0;i<nums.size();i++){
            CS+=nums[i];
            MS=max(CS,MS);
            if (CS<0){
                CS=0;
            }
        }
        return MS;
        
    }
};
