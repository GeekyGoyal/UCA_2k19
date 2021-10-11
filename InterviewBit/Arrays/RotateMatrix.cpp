/* Problem Link: https://www.interviewbit.com/problems/rotate-matrix/ */

void Solution::rotate(vector<vector<int> > &A) {
    int n = A.size();
    // Take Transpose
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i < j) {
                swap(A[i][j], A[j][i]);
            }
        }
    }
    // Reverse each Row
    for(int i = 0; i < n; i++) {
        reverse(A[i].begin(), A[i].end());
    }
}
