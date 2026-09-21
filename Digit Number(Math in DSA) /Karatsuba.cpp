/*
Problem Name: Karatsuba Multiplication

Approach:
- Divide each number into two halves:
  x = a * 10^m + b
  y = c * 10^m + d

- Instead of performing 4 multiplications (ac, ad, bc, bd),
  use only 3 recursive multiplications:
  1. ac
  2. bd
  3. (a + b) * (c + d)

- Calculate the middle terms using:
  ad + bc = (a + b)(c + d) - ac - bd

- Combine the three parts:
  x * y = ac * 10^(2m)
        + (ad + bc) * 10^m
        + bd

- Repeat the same process recursively until the numbers
  become single-digit.

Time Complexity: O(n^log2(3)) ≈ O(n^1.585)

Space Complexity: O(log n) due to the recursive call stack.

Key Concepts Used:
- Divide and Conquer
- Recursion
- Mathematical Manipulation
*/
#include <iostream>
#include <string>
using namespace std;

long long karatsuba(long long x, long long y) {
    // Base case
    if (x < 10 || y < 10) {
        return x * y;
    }

    // Find number of digits
    int n = max(to_string(x).length(), to_string(y).length());
    int m = n / 2;

    long long power = 1;
    for (int i = 0; i < m; i++) {
        power *= 10;
    }

    // Split x into a and b
    long long a = x / power;
    long long b = x % power;

    // Split y into c and d
    long long c = y / power;
    long long d = y % power;

    // Three recursive multiplications
    long long ac = karatsuba(a, c);
    long long bd = karatsuba(b, d);
    long long abcd = karatsuba(a + b, c + d);

    // Calculate ad + bc
    long long ad_bc = abcd - ac - bd;

    // Combine the results
    return ac * power * power
         + ad_bc * power
         + bd;
}

int main() {
    long long x = 1234;
    long long y = 5678;

    cout << karatsuba(x, y) << endl;

    return 0;
}


