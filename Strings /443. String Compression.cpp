/*
------------------------------------------------------------
LeetCode Problem: 443. String Compression
Language: C++
------------------------------------------------------------

Approach:
1. Use an index (idx) to overwrite the original array with the compressed result.
2. Traverse the character array and count the frequency of each consecutive character.
3. If a character appears only once, store it directly.
4. If a character appears more than once:
   - Store the character.
   - Convert its count into a string using to_string().
   - Store each digit of the count separately in the array.
5. Since the loop variable (i) is also incremented inside the while loop,
   decrement it once (i--) before the next iteration to avoid skipping characters.
6. Resize the vector to the compressed length and return the final size.

Time Complexity: O(n)
- Each character is visited only once.

Space Complexity: O(1)
- Compression is performed in-place (excluding the temporary string used for the count).

------------------------------------------------------------
*/



class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0;

        for (int i = 0; i < n; i++) {
            char ch = chars[i];
            int count = 0;

            while (i < n && chars[i] == ch) {
                count++;
                i++;
            }

            if (count == 1) {
                chars[idx] = ch;
                idx++;
            } else {
                chars[idx] = ch;
                idx++;

                string str = to_string(count);

                for (char dig : str) {
                    chars[idx] = dig;
                    idx++;
                }
            }

            i--;   // because the for loop will increment i again
        }

        chars.resize(idx);
        return idx;
    }
};

