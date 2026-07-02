/*
Problem: Pow(x, n)

Approach:
- Use Binary Exponentiation (Exponentiation by Squaring).
- Initialize answer as 1.0.
- If the exponent is negative, convert x to 1/x and make the exponent positive.
- While the exponent is greater than 0:
    - If the current exponent is odd, multiply the answer by x.
    - Square the base (x *= x).
    - Divide the exponent by 2 to process the next binary bit.
- Return the final answer.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    double myPow(double x, int n) {
        long binform=n;
        double ans=1.0;
        if(n<0){
            x=1/x;
            binform=-binform;
        }
        while(binform>0){
            if (binform%2==1){
                ans*=x;
                
            }
            x*=x;
            binform /=2;
        }
        return ans;
        
    }
};
