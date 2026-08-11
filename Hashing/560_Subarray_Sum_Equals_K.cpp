/*
Problem: Subarray Sum Equals K

Approach:
1. Calculate the prefix sum of the array.
   prefixSum[i] represents the sum of elements from index 0 to i.

2. For every current prefix sum, we want to find whether there
   was a previous prefix sum such that:

       currentPrefixSum - previousPrefixSum = k

   Rearranging:

       previousPrefixSum = currentPrefixSum - k

3. Use an unordered_map to store:
       Prefix Sum -> Frequency

   This tells us how many times each prefix sum has appeared.

4. For every prefix sum:
   - Calculate:
         val = prefixSum - k
   - Check whether 'val' exists in the map.
   - If it exists, add its frequency to count because each
     occurrence represents a valid subarray whose sum is k.
   - Store the current prefix sum in the map by increasing
     its frequency.

5. Initialize:
       m[0] = 1

   This represents an empty prefix with sum 0 and allows us
   to correctly count subarrays that start from index 0.

Why this works:
If:

    currentPrefixSum - previousPrefixSum = k

then the elements between the previous prefix and current
prefix have sum exactly k.

Time Complexity: O(n)

Space Complexity: O(n)
*/

class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n=arr.size();
        int count=0;
        vector<int>prefixsum(n,0);
        prefixsum[0]=arr[0];
        for(int i=1;i<n;i++){
            prefixsum[i]=prefixsum[i-1]+arr[i];

        }
        unordered_map<int,int>m;//PS,FREQ
        for (int j=0;j<n;j++){
           if(prefixsum[j]==k) count++;
           int val=prefixsum[j]-k;
           if(m.find(val)!=m.end()){
            count+=m[val];
           }
           if (m.find(prefixsum[j])==m.end()){
            m[prefixsum[j]]=0;

           }
           m[prefixsum[j]]++; 

        }
        return count;



        
    }
};
