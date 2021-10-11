/* Problem Link: https://www.interviewbit.com/problems/first-missing-integer/ */

int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    for(int i = 0; i < n; i++) {
        if(A[i] > 0 && A[i] <= n) { 
           // To avoid endless swapping 
            if(A[A[i]-1] != A[i]) {
                swap(A[i], A[A[i]-1]);
                i--;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(A[i] != i+1) {
            return i+1;
        }
    }
    return n+1;
}
