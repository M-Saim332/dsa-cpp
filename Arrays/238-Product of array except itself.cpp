/*
    LeetCode 238: Product of Array Except Self

    Approach:
    1. Traverse from left to right to store the prefix product in the answer array.
       ans[i] contains the product of all elements before index i.
    2. Traverse from right to left while maintaining a running suffix product.
       Multiply the suffix product with the corresponding prefix product stored in ans.
    3. The final answer at each index is:
       Product of elements on the left × Product of elements on the right.

    Time Complexity: O(n)
    Space Complexity: O(1) Extra Space
    (The output array is not counted as extra space.)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,1);
        //prefix==>ans
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]*nums[i-1];
        }
        //Suffix 
        int suffix=1;
        for (int j=n-2;j>=0;j--){
            suffix*=nums[j+1];
            ans[j]*=suffix;
        }
        return ans;


    }
};
