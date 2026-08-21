/*
 * APPROACH FOR STRING PERMUTATIONS (NO DUPLICATES):
 * 
 * 1. DECISION TREE VIA RECURSION (DFS):
 *    - Process the string index by index, starting from 'idx = 0' up to 'length - 1'.
 *    - At position 'idx', every character from index 'idx' to the end is a candidate 
 *      to be placed at 'idx'.
 * 
 * 2. NO PRUNING NEEDED:
 *    - Since all characters are distinct, every swap produces a unique permutation branch.
 *    - No hash set or visited tracking is required.
 * 
 * 3. BACKTRACKING STEPS:
 *    - Choose: Swap s[idx] and s[i] to place the candidate character at position 'idx'.
 *    - Explore: Recurse to fix the next character position (idx + 1).
 *    - Un-choose (Backtrack): Swap s[idx] and s[i] back to restore the original 
 *      string state for the next iteration.
 * 
 * 4. BASE CASE:
 *    - When 'idx == string.length()', a complete unique permutation is formed.
 *    - Append the current state of the string into the answer array and return.
 */
class Solution {
private:
    void getperm(string& s, int idx, vector<string>& ans) {
        // Base Case: All character positions are fixed
        if (idx == s.length()) {
            ans.push_back(s);
            return;
        }

        // Try placing every character from idx to length-1 at position 'idx'
        for (int i = idx; i < s.length(); i++) {
            // Action: Swap candidate character into position idx
            swap(s[idx], s[i]);

            // Recurse: Move to the next index position
            getperm(s, idx + 1, ans);

            // Backtrack: Restore original string order for the next loop iteration
            swap(s[idx], s[i]);
        }
    }

public:
    vector<string> findPermutation(string s) {
        vector<string> ans;
        getperm(s, 0, ans);
        return ans;
    }
};
