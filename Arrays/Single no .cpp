/*
Problem: Single Number
Platform: LeetCode
Problem No: 136
Difficulty: Easy

Description:
Given a non-empty array of integers where every element appears exactly twice
except for one element, find that single element.

You must implement a solution with:
- Time Complexity: O(n)
- Extra Space Complexity: O(1)

Approach:
Use the Bitwise XOR operator (^).

Key Properties of XOR:
1. a ^ a = 0
2. a ^ 0 = a
3. XOR is commutative and associative.

Since every duplicate number cancels itself out (a ^ a = 0),
only the unique number remains after XOR-ing all elements.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int ans=0;
        for(int  val:nums){
            ans=ans^val;
        }
        return ans;
    }
};




