/* Problem Link: https://www.interviewbit.com/problems/set-matrix-zeros/ */

/* Time Complexity: O(N*M)
*  Space Complexity: O(1) (Inplace) */

void Solution::setZeroes(vector<vector<int> > &A) {
    int col0 = 1, rows = A.size(), cols = A[0].size();
    for(int i = 0; i < rows; i++) {
        if(A[i][0] == 0) {
            col0 = 0;
        }
        for(int j = 1; j < cols; j++) {
            if(A[i][j] == 0) {
                A[i][0] = A[0][j] = 0;
            }
        }
    }
    for(int i = rows-1; i >= 0; i--) {
        for(int j = cols-1; j >= 1; j--) {
            if(A[i][0] == 0 || A[0][j] == 0) {
                A[i][j] = 0;
            }
        }
        if(col0 == 0) {
            A[i][0] = 0;
        }
    }
}
