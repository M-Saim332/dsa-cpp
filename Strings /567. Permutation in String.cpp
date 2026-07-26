/*
## Approach

1. Create a frequency array of size 26 for `s1` and store the frequency of each character.
2. Set the window size equal to the length of `s1`.
3. Traverse `s2` and treat each index as the starting point of a window.
4. For every window, create another frequency array of size 26 and count the characters present in that window.
5. Compare the frequency array of the current window with the frequency array of `s1`.
6. If both frequency arrays are identical, it means the current window is a permutation of `s1`, so return `true`.
7. If no window matches after checking all possible windows, return `false`.

### Time Complexity

* **O((n - m + 1) × (m + 26)) ≈ O(n × m)**

  * `n` = length of `s2`
  * `m` = length of `s1`

### Space Complexity

* **O(26) ≈ O(1)**
  * Two frequency arrays of fixed size 26 are used.
*/

class Solution {
public:
    bool isfreqsame(int freq1[],int freq2[]){
        for (int i=0;i<26;i++){
            if (freq1[i]!=freq2[i]){
                return false;

            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int freq[26]={0};
        for (int i=0;i<s1.length();i++){
            freq[s1[i]-'a']++;
        }
        int windsize=s1.length();
        for (int i=0;i<s2.length();i++){
            int idx=i , winidx=0;
            int windfreq[26]={0};
            while(winidx<windsize && idx<s2.length()){
                windfreq[s2[idx]-'a']++;
                winidx++;idx++;

            }
            if (isfreqsame(freq,windfreq)){//Found
                return true;
            }
        }
        return false;
        
    }

};
