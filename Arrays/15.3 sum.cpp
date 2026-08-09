/*
Problem Name: 15. 3Sum (Not Optimied approach)

Problem Statement:
Find all unique triplets in the array whose sum is equal to 0.

Approach:
- Use three nested loops to check every possible combination of 3 elements.
- If the sum of the three elements is 0, we have found a valid triplet.
- Sort the triplet so that the same triplet always has the same order.
- Use a set to store unique triplets and avoid duplicates.
- If the triplet is not already present in the set, insert it into the set and answer.

Time Complexity:
O(n^3 log 3) ≈ O(n^3)

Space Complexity:
O(n) for storing unique triplets.

Key Concepts Used:
- Brute Force
- Nested Loops
- Set
- Sorting
- Duplicate Handling
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>>ans;
        set<vector<int>>s;//set unique triplets
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0) {
                        vector<int>trip={nums[i],nums[j],nums[k]};
                        sort(trip.begin(),trip.end());

                        if (s.find(trip)==s.end()){
                            s.insert(trip);
                            ans.push_back(trip);
                        }

                    }

    
                }
            }
        }
        return ans;

    }
};
