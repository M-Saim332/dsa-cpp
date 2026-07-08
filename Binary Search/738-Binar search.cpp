/*
Leet code problem=738-Binary Search
Approach:
 Binary search only works on the sorted arrays.
  We find the mid if target is less than mid we will check in the first half else in 2nd half.
  Time Complexity =O(logn)
  */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st=0;
        int end=nums.size()-1;
        while(st<=end){
            int mid = st + (end - st) / 2;
            if (target<nums[mid]){
               end=mid-1;
            }
            else if(target>nums[mid]){
                
                st=mid+1;

            }
            else{
                return mid;
            }
        }
        return -1;
        
    }
};
