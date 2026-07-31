/* # Count Primes (LeetCode 204)

## Problem Statement

Given an integer `n`, return the number of **prime numbers** that are **strictly less than** `n`.

## Approach


// 1. If n <= 2, return 0 since no primes exist below 2.
// 2. Create a boolean array and mark every number as prime.
// 3. Mark 0 and 1 as non-prime.
// 4. Use the Sieve of Eratosthenes to mark multiples of each prime as non-prime.
// 5. Count all numbers that are still marked as prime.
// 6. Return the count.
## Time Complexity
 O(n log log n)
## Space Complexity

```cpp
// O(n)
```

---

## Key Concepts Used
// - Sieve of Eratosthenes
// - Prime Numbers
// - Boolean Array

*/



class Solution {
public:
    int countPrimes(int n) {

        // No prime numbers exist below 2
        if (n <= 2)
            return 0;

        // Assume all numbers are prime initially
        vector<bool> isPrime(n, true);

        // 0 and 1 are not prime
        isPrime[0] = false;
        isPrime[1] = false;

        // Mark multiples of each prime as non-prime
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Count remaining prime numbers
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                count++;
            }
        }

        return count;
    }
};
```
