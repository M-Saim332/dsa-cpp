#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int get_max_sum(int mat[][3], int rows, int cols) {
    int maxrowsum = INT_MIN;

    for (int i = 0; i < rows; i++) {
        int rowsumI = 0;

        for (int j = 0; j < cols; j++) {
            rowsumI += mat[i][j];
        }

        maxrowsum = max(maxrowsum, rowsumI);
    }

    return maxrowsum;
}

int main() {
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int sum = get_max_sum(mat, 3, 3);

    cout << "Maximum row sum = " << sum << endl;

    return 0;
}
