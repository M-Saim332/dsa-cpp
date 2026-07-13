/*
    Problem: Book Allocation Problem

    Question:
    Given an array where each element represents the number of pages in a book
    and an integer M representing the number of students, allocate the books
    such that:

    1. Each student gets at least one book.
    2. Books are allocated in contiguous order.
    3. Each book is allocated to only one student.
    4. The maximum number of pages assigned to any student is minimized.

    Return the minimum possible value of the maximum pages assigned to a student.
    If the number of students is greater than the number of books, return -1.

    Example:
    Input:
    Books = [15, 17, 20]
    Students = 2

    Output:
    32

    Explanation:
    Student 1 -> [15, 17] = 32 pages
    Student 2 -> [20] = 20 pages

    Maximum pages assigned = max(32, 20) = 32

    ------------------------------------------------------------

    Approach:
    - Use Binary Search on the Answer.
    - The search space is from 0 (or max(arr) in the optimized approach)
      to the sum of all book pages.
    - For every mid value, check if it is possible to allocate all books
      to at most M students such that no student receives more than
      'mid' pages.
    - If the allocation is possible, store the answer and search for
      a smaller valid answer.
    - Otherwise, search for a larger answer.

    Time Complexity:
    O(N * log(sum))

    Space Complexity:
    O(1)
    -----------------------------------------------------------
    
*/
//Code:
#include <iostream>
#include <vector>
using namespace std;


bool isvalid(vector<int>arr,int n,int m,int maxallowedpages){
    int stu=1 ,pages=0;
    for (int i=0;i<=n;i++){ //O(n)
        if (arr[i]>maxallowedpages){
            return false;
        }
        if(pages+arr[i]<=maxallowedpages){
            pages=arr[i];
        }else{
            stu++;
            pages=arr[i];
        }
    }
    return stu>m ? false:true;
}
int allocatebook(vector<int>&arr,int n,int m ){ //
        if(m>n){
            return -1;
            
        }
        int sum=0;
        // for the minimum and the maximum range
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        int ans=-1;
        int st=0; int end=sum; //range of the possible elements
        while(st<=end){ //(Logn)
            int mid =st +(end-st)/2;
            if (isvalid(arr,n,m,mid)){//move in the left to find more smaller answer
              ans=mid;
              end=mid-1;
            }else{//move in the right
                st=mid+1;
            }
        }
        return ans;
}
int main() {
    vector<int>arr={15,17,20};
    int n=arr.size();
    int m=2;
    cout<<allocatebook(arr,n,m)<<endl;
    

    return 0;
}




