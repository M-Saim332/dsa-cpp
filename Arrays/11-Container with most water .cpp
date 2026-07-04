/*
    LeetCode 11: Container With Most Water

    Approach:
    - Use two pointers: one at the beginning and one at the end.
    - Calculate the area using:
          width = j - i
          height = min(height[i], height[j])
          area = width * height
    - Update the maximum area found.
    - Move the pointer with the smaller height inward, as it is the limiting factor.
    - Continue until the two pointers meet.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater=0;
        int n=height.size();
         int i=0;
         int j =n-1;
        while(i<j){
            int w=j-i;
            int ht=min(height[i],height[j]);
            int area= w*ht;
            maxwater=max(maxwater,area);
            height[i]<height[j] ? i++:j--;

        }
        return maxwater;

    }
};
