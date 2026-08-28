/*
===========================================================
Problem: 131. Palindrome Partitioning
Platform: LeetCode
Difficulty: Medium
Topic: Recursion & Backtracking
===========================================================

Problem Statement:
Given a string s, partition s such that every substring
of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:
Input:  s = "aab"

Output:
[
    ["a","a","b"],
    ["aa","b"]
]

-----------------------------------------------------------
Approach:
-----------------------------------------------------------

1. Start from the beginning of the string.

2. Try every possible prefix/substring:
       "a"
       "aa"
       "aab"

3. Check whether the selected substring is a palindrome.

4. If it is a palindrome:
       - Add it to the current partition.
       - Recursively solve the remaining string.
       - Remove it using pop_back() to backtrack.

5. When the remaining string becomes empty, we have
   found a complete valid partition, so add it to ans.

-----------------------------------------------------------
Backtracking Pattern:
-----------------------------------------------------------

    Choose
       ↓
    Explore
       ↓
    Undo

    current.push_back(part);
    getallparts(...);
    current.pop_back();

-----------------------------------------------------------
Palindrome Check:
-----------------------------------------------------------

Use two pointers:
    i → starts from beginning
    j → starts from end

If s[i] != s[j], the string is not a palindrome.

Otherwise move:
    i++
    j--

-----------------------------------------------------------
Time Complexity:
-----------------------------------------------------------

O(n * 2^n)

There can be up to O(2^n) possible partitions,
and checking/copying substrings adds an O(n) factor.

-----------------------------------------------------------
Space Complexity:
-----------------------------------------------------------

O(n)

Recursion depth and the current partition require O(n)
auxiliary space, excluding the output.

-----------------------------------------------------------
Key Concepts:
-----------------------------------------------------------

- Recursion
- Backtracking
- Palindrome Checking
- substr()
- Two Pointers
===========================================================
*/
class Solution {
public:

    // Check if a string is a palindrome
    bool ispalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }

    // Generate all possible palindrome partitions
    void getallparts(
        string s,
        vector<string>& current,
        vector<vector<string>>& ans
    ) {

        // Base Case
        if (s.size() == 0) {
            ans.push_back(current);
            return;
        }

        // Try every possible substring
        for (int i = 0; i < s.size(); i++) {

            string part = s.substr(0, i + 1);

            // Only choose if palindrome
            if (ispalindrome(part)) {

                // Choose
                current.push_back(part);

                // Explore
                getallparts(
                    s.substr(i + 1),
                    current,
                    ans
                );

                // Backtrack / Undo
                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> current;

        getallparts(s, current, ans);

        return ans;
    }
};




