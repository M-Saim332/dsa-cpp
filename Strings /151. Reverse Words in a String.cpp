/*
LeetCode 151. Reverse Words in a String

Approach:
- Reverse the entire string.
- Traverse the reversed string and extract each word.
- Reverse each extracted word to restore its original character order.
- Append each word to the answer string, separating words with a single space.
- Remove the leading space from the final answer using substr(1).

Time Complexity: O(n)
Space Complexity: O(n)
*/


class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        reverse(s.begin(), s.end());

        string ans = "";

        for (int i = 0; i < n; i++) {
            string word = "";

            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            reverse(word.begin(), word.end());

            if (word.length() > 0) {
                ans += " " + word;
            }
        }

        return ans.substr(1);
    }
};
