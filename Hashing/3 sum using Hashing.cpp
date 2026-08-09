/*
Problem Name: 15. 3Sum

Problem Statement:
Find all unique triplets in the array whose sum is equal to 0.

Approach:
- Fix the first element using the outer loop.
- For every nums[i], calculate the required value:
      target = -nums[i]
- Use a set to store elements already seen while traversing with j.
- For every nums[j], calculate the third value needed:
      third = target - nums[j]
- If third is already present in the set, we found a valid triplet.
- Sort the triplet and insert it into another set to avoid duplicate triplets.
- Finally, convert the set of unique triplets into the answer vector.

Time Complexity:
O(n² log n)

Space Complexity:
O(n²) for storing unique triplets and the hash/set elements.

Key Concepts Used:
- Hashing
- Set
- Nested Loops
- Sorting
- Duplicate Handling
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       int n =nums.size();
       set<vector<int>>Uniquretriplets;
       for(int i=0;i<n;i++){
            int targ=-nums[i];
            set<int>s;
            for(int j=i+1;j<n;j++)
            {
                int third=targ-nums[j];

                if(s.find(third)!=s.end()){
                    vector<int>trip={nums[i],nums[j],third};
                     sort(trip.begin(),trip.end());
                     Uniquretriplets.insert(trip);
                }
                s.insert(nums[j]); 

            }
       }
       
       vector<vector<int>>ans(Uniquretriplets.begin(),Uniquretriplets.end());
       return ans;
    }
};
