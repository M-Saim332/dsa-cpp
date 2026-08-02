#include <iostream>
#include <utility>
using namespace std;
int matrix[3][3]={{1,2,3},{0,18,9},{1,7,6}};
int rows=3;
int cols=3;
 pair<int,int >linearsearch(int key){
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (matrix[i][j]==key){
            return {i,j};
            }
        }
    }
    return {-1,1};
 }
        

int main() {
    
    pair<int, int> key = linearsearch(7);

    cout << key.first << " " << key.second << endl;

    return 0;
}
