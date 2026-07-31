/*
Problem Name:7 Reverse Integer
-------------------------------------
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to
go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
---------------------------------------
Approach:
1. Initialize a variable to store the reversed number.
2. Extract the last digit using the modulo (%) operator.
3. Before adding the digit, check if reversing will cause integer overflow.
4. If overflow is possible, return 0.
5. Otherwise, append the digit to the reversed number.
6. Remove the last digit from the original number and repeat until it becomes 0.
7. Return the reversed integer.
--------------------------------------
Time Complexity:
O(log₁₀N)
- We process each digit exactly once.

Space Complexity:
O(1)
- Only a few integer variables are used.
----------------------------------------
*/
class Solution {
public:
    int reverse(int n) {
         int revnum=0;
        while(n!=0){
            int dig=n%10;
            if (revnum>INT_MAX/10 || revnum<INT_MIN/10){
                return 0;
            }
            revnum=revnum*10+dig;
            n=n/10;
        }
        return revnum; 
    }
};


 
 
 */
