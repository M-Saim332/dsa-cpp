/*
Problem Name:
Find the Duplicate Number

Problem Statement:
Given an array containing n + 1 integers where each integer is
between 1 and n, find the number that appears more than once.

Approach:
- Treat the array like a Linked List where each value points to the next index.
- Use two pointers: slow and fast.
- Slow moves one step at a time, while fast moves two steps.
- Since one number is repeated, a cycle is created in this Linked List.
- First, move slow and fast until they meet inside the cycle.
- Then reset slow to the starting point.
- Move both pointers one step at a time.
- When they meet again, that position is the duplicate number.

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Concepts Used:
- Linked List
- Slow and Fast Pointers
- Floyd's Cycle Detection Algorithm
- Cycle Detection
*/

class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int slow=arr[0],fast=arr[0];
        do{
            slow=arr[slow];//1
            fast=arr[arr[fast]];//2

        }while(slow!=fast);
        slow=arr[0];

        while(slow!=fast){
            slow=arr[slow];//1
            fast=arr[fast];//1

        }
        return slow;
        
        
    }
};
