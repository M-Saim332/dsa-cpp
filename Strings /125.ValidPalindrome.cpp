/*
problem=125
Problem Name= Valid Palindrome
Approcah:
* Use two pointers: `st` at the beginning and `end` at the end of the string.
* Skip all non-alphanumeric characters from both sides.
* Convert both characters to lowercase and compare them.
* If the characters are different, return `false`.
* If they match, move both pointers toward the center.
* Continue until the pointers meet or cross.
* If no mismatch is found, return `true`.

**Time Complexity:** `O(n)`
**Space Complexity:** `O(1)`

*/
class Solution {
public:
    bool isalphanumeric(char c) {
        c = tolower(c);

        if ((c >= '0' && c <= '9') ||
            (c >= 'a' && c <= 'z'))
            return true;

        return false;
    }

    bool isPalindrome(string s) {
        int st = 0;
        int end = s.length() - 1;

        while (st <= end) {
            if (!isalphanumeric(s[st])) {
                st++;
                continue;
            }

            if (!isalphanumeric(s[end])) {
                end--;
                continue;
            }

            if (tolower(s[st]) != tolower(s[end])) {
                return false;
            }

            st++;
            end--;
        }

        return true;
    }
};


/*
WITH STL FUNCTIONS
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {

            while (left < right && !isalnum(s[left]))
                left++;

            while (left < right && !isalnum(s[right]))
                right--;

            if (tolower(s[left]) != tolower(s[right]))
                return false;

            left++;
            right--;
        }

        return true;
    }
};











*/
