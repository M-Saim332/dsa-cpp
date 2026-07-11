/*
leetcode problem: 852
  Problem name =Peak Index in a Mountain Array
Approach:
- Since the array is a mountain array, the peak element is greater than both of its adjacent elements.
- Apply Binary Search to find the peak efficiently.
- Find the middle index.
- If the middle element is greater than both its left and right neighbors, it is the peak.
- If the element on the right is greater than the middle element, the peak lies on the right side, so move the start pointer.
- Otherwise, the peak lies on the left side, so move the end pointer.
- Repeat until the peak index is found.

Time Complexity: O(log n)
Space Complexity: O(1)
  */
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n= arr.size();
        int st=1;
        int end=n-1;
        while(st<=end){
            int mid=st + (end-st)/2;
            if (arr[mid+1]<arr[mid] && arr[mid-1]<arr[mid]){
                return mid;
            }
            if (arr[mid+1]>arr[mid]){//right search
               st=mid+1;

            }else{//left search
                end=mid-1;

            }

        }
        return -1;
        
        
        
        
    }
};

