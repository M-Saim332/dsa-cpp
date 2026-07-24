/*
Problem no:1910
Problem Solution:Remove All Occurrences of a Substring
### Approach

1. Keep checking whether the substring `part` exists in the string `s` using `find()`.
2. If `part` is found, `find()` returns its starting index.
3. Remove that occurrence from `s` using `erase(index, part.length())`.
4. Repeat this process until `find()` can no longer locate `part` in the string.
5. Return the final modified string after all occurrences have been removed.

### Time Complexity

* **O(n × m)** (can be higher in the worst case due to repeated `find()` and `erase()` operations, where `n` is the length of `s` and `m` is the length of `part`).

### Space Complexity

* **O(1)** (ignoring the space used by the input string, as the modifications are performed in place).


*/
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length()>0 && s.find(part)<s.length()){
            (s.erase(s.find(part),part.length()));
        }
        return s;
        
    }
};
