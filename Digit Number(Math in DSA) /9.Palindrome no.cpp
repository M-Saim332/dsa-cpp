/*
Problem Name: 9 . Palindrome Number

Approach:
1. If the number is negative, return false because negative numbers cannot be palindromes.
2. Reverse the given number using a separate reverse() function.
3. Compare the original number with the reversed number.
4. If both are equal, the number is a palindrome; otherwise, it is not.

Time Complexity:
O(log₁₀N)
- Reversing the number takes one pass through its digits.

Space Complexity:
O(1)
- Only a few integer variables are used.
*/
class Solution {
public:
    int reverse(int n) {
        int revnum = 0;

        while (n != 0) {
            int dig = n % 10;

            if (revnum > INT_MAX / 10 || revnum < INT_MIN / 10) {
                return 0;
            }

            revnum = revnum * 10 + dig;
            n = n / 10;
        }

        return revnum;
    }

    bool isPalindrome(int n) {
        if (n < 0)
            return false;

        int revnum = reverse(n);

        return n == revnum;
    }
};
