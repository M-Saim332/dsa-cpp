/*
Leetcode problem no=33
Problem name=Search in Rotated Sorted Array

Approach:
---Using the Binary search approach that either part of the array is sorted 
1. Find Mid.

2. Is left sorted?
      |
     Yes
      |
Is Target in left side?
   |          |
 Yes         No
end=mid-1   st=mid+1

-------------------------

Left is not sorted ?

So Right must be sorted

Is Target in right ?
    |          |
   Yes        No
st=mid+1   end=mid-1

Time Complexity =O(logn)
  */

class Solution {
public:
    int search(vector<int>& A, int target) {
       
     int st = 0;
     int end = A.size() - 1;
 
    while (st <= end) {

        int mid = st + (end - st) / 2;

        // Target found
        if (A[mid] == target) {
            return mid;
        }

        // Check if left half is sorted
        if (A[st] <= A[mid]) {

            // Is target inside left sorted half?
            if (A[st] <= target && target <= A[mid]) {
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }

        // Otherwise, right half is sorted
        else {

            // Is target inside right sorted half?
            if (A[mid] <= target && target <= A[end]) {
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
    }

    return -1; // Target not found
};

             

    
        
    



  
