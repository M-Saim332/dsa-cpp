/*
Problem: Fibonacci Number

Approach:
1. If n is 0 or 1, return n because these are the base cases.
2. Instead of using recursion, store only the previous two Fibonacci numbers.
3. Initialize:
      prev = 0
      curr = 1
4. Run a loop from 2 to n.
5. Calculate the next Fibonacci number using:
      next = prev + curr
6. Move the values forward:
      prev = curr
      curr = next
7. Return curr as the nth Fibonacci number.

Why this approach?
The recursive approach repeatedly calculates the same Fibonacci numbers,
which makes it inefficient. The iterative approach calculates each number
only once and uses constant extra space.

Time Complexity: O(n)
Space Complexity: O(1)

Key Concepts:
- Iteration
- Variables
- Dynamic updating
- Fibonacci sequence
*/


class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1) return n;

        int prev=0;
        int curr=1;
        for(int i=2;i<=n;i++){
            int next = prev+curr;
            prev=curr;
            curr=next;
        }
        return curr;
        
    }
};
