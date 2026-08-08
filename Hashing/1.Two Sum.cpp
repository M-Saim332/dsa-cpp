/*
Problem Name:
Two Sum

Problem Statement:
Given an array of integers and a target value, find two indices
whose corresponding values add up to the target.

Approach:

* Use an unordered_map to store each number and its index.
* For every element, calculate the required number:
  required = target - current number
* Check if the required number already exists in the map.
* If it exists, we found the two numbers, so store their indices.
* If it does not exist, store the current number and its index.
* This avoids checking every possible pair.

Time Complexity:
O(n) average

Space Complexity:
O(n)

Key Concepts Used:

* unordered_map
* Hashing
* Complement calculation
* Array traversal
  */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int targ) {
        unordered_map<int,int>m;
        vector<int>ans;
        for (int i=0;i<nums.size();i++){
            int first=nums[i];
            int sec=targ-first;
            if(m.find(sec)!=m.end()){
                ans.push_back(i);
                ans.push_back(m[sec]);
                break;
            }
            m[first]=i;



        } 
        return ans;

        
    }
};
