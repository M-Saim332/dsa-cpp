/*
Problem Name:
Find Missing and Repeated Values

Problem Statement:
Given an n x n grid containing numbers from 1 to n²,
one number is repeated and one number is missing.
Find both numbers.

Approach:
- Use an unordered_set to keep track of the numbers already seen.
- For every grid element, check if it already exists in the set.
- If it exists, it is the repeated number.
- Otherwise, insert it into the set.
- Calculate the expected sum of numbers from 1 to n².
- Calculate the actual sum of all elements in the grid.
- Use the repeated number and the difference between expected and actual sum
  to find the missing number.

Time Complexity:
O(n²)

Space Complexity:
O(n²)

Key Concepts Used:
- unordered_set
- Hashing
- Set find()
- Sum formula
- Matrix traversal
*/

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>ans;
        unordered_set<int>s;
        int n= grid.size();
        int a,b;
        int expsum=0,actualsum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                actualsum+=grid[i][j];

                if(s.find(grid[i][j])!=s.end()){
                   a=grid[i][j];
                   ans.push_back(a);
                }
                s.insert(grid[i][j]);
            }

           

        }
        expsum=n*n *(n*n +1)/2;
        b = expsum + a - actualsum;
        ans.push_back(b);
        return ans;
        
    }
};
