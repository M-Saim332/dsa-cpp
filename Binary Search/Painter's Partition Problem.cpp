/*
    Problem: Painter's Partition Problem

    Question:
    Given an array where each element represents the time required to paint
    a board and an integer M representing the number of painters, assign the
    boards such that:

    1. Each painter paints only contiguous boards.
    2. Each board is painted by exactly one painter.
    3. Every painter paints at least one board.
    4. The time taken by a painter is the sum of the times of the boards
       assigned to them.
    5. Minimize the maximum time taken by any painter.

    Return the minimum time required to paint all the boards.

    Example:
    Input:
    Boards = [40, 30, 10, 20]
    Painters = 2

    Output:
    60

    Explanation:
    Painter 1 -> [40, 20] ❌ (Not Allowed, boards must be contiguous)

    Valid Allocation:
    Painter 1 -> [40]
    Painter 2 -> [30, 10, 20]

    Time taken:
    Painter 1 = 40
    Painter 2 = 60

    Maximum time = max(40, 60) = 60

    This is the minimum possible maximum time.

    ------------------------------------------------------------

    Approach:
    - This problem is solved using Binary Search on the Answer.
    - The minimum possible answer is 0 (or the maximum board time in the
      optimized approach).
    - The maximum possible answer is the sum of all board times.
    - For every mid value, check if all boards can be assigned to at most
      M painters such that no painter paints more than 'mid' units of time.
    - If the allocation is possible, store the answer and search for a
      smaller valid value.
    - Otherwise, search for a larger value.

    Time Complexity:
    O(N * log(sum))

    Space Complexity:
    O(1)
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;


bool ispossible(vector<int>arr,int n,int m,int maxallowed){
    int painters=1; 
    int time=0;
    for(int i=0;i<n;i++)
    {
        if(time+arr[i]<=maxallowed){
            time+=arr[i];
        }else{
            painters++;
            time=arr[i];
        }
       
    }
     return painters<=m;
}

int mintimetopaint(vector<int>arr,int n,int m){
    int sum=0;
    int maxvalue=INT_MIN;
    for (int i=0;i<n;i++){
        sum+=arr[i];
        maxvalue=max(maxvalue,arr[i]);
    }
    int st=0;
    int end=sum;
    int ans=-1;
    while(st<=end){
        int mid= st+ (end-st)/2;
        if (ispossible(arr,n,m,mid)){//left
        ans=mid;
        end=mid-1;
            
        }else{//right
        st=mid+1;
            
        }
    }
    return ans;
}


int main() {
    vector<int>arr={40,30,10,20};
    int m=2;
    int n=arr.size();
    cout<<mintimetopaint(arr,n,m)<<endl;


    return 0;
}
