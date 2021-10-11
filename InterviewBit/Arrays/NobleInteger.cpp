/* Problem Integer: https://www.interviewbit.com/problems/noble-integer/ */

// Time Complexity: O(NLogN)
int Solution::solve(vector<int> &A) {
    int size = A.size();
    sort(A.begin(), A.end());
    for(int i = 0; i < size; i++) {
        if(A[i] == A[i+1]) {
            continue;
        }
        if(A[i] == size-i-1) {
            return 1;
        }
        if(A[size-1] == 0) {
            return 1;
        }
    }
    return -1; 
}
