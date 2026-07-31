/*
Problem Statement:

Given an integer n, determine whether it is an Armstrong number. Return true if it is, otherwise return false.

  Armstrong numbers are the those numbers whose sum  of cube of individual no is equal to the original no e.g;153.
  
  
===Steps to Solve======
Store the original number.
Count the total number of digits.
Extract each digit using % 10.
Raise the digit to the power of the number of digits.
Add these values together.
Compare the sum with the original number.
If equal → Armstrong number.
Otherwise → Not an Armstrong number.
=-------------
Time Complexity
O(d), where d is the number of digits.
Space Complexity
O(1)
*/
#include <iostream>
#include <cmath>   // For pow() function
using namespace std;

// Function to count the total number of digits
int countDigits(int n) {

    // Special case: 0 has one digit
    if (n == 0)
        return 1;

    int count = 0;

    // Count digits by repeatedly removing the last digit
    while (n != 0) {
        count++;
        n = n / 10;
    }

    return count;
}

// Function to check whether a number is an Armstrong number
bool isArmstrong(int n) {

    // Store the original number for comparison later
    int original = n;

    // Find the total number of digits
    int digits = countDigits(n);

    int sum = 0;

    // Traverse each digit of the number
    while (n != 0) {

        // Extract the last digit
        int dig = n % 10;

        // Raise the digit to the power of total digits
        // and add it to the sum
        sum += pow(dig, digits);

        // Remove the last digit
        n = n / 10;
    }

    // If the calculated sum equals the original number,
    // then it is an Armstrong number
    return sum == original;
}

int main() {

    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isArmstrong(num))
        cout << num << " is an Armstrong Number.";
    else
        cout << num << " is not an Armstrong Number.";

    return 0;
}

  
