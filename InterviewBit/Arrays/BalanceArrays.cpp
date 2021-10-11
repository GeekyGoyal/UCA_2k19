/* Problem Link: https://www.interviewbit.com/problems/balance-array/ */

int Solution::solve(vector<int> &A) {
    int res = 0, oddSum = 0, evenSum = 0, od = 0, ev = 0;
    for(int i = 0; i < A.size(); i++) {
        if(i%2 == 0) {
            evenSum += A[i];
        }
        else {
            oddSum += A[i];
        }
    }
    for(int i = 0; i < A.size(); i++) {
        if(i % 2 == 0) {
            evenSum -= A[i];
        }
        else {
            oddSum -= A[i];
        }
        if(evenSum + od == oddSum + ev) {
            res++;
        }
        if(i % 2 == 0) {
            ev += A[i];
        }
        else {
            od += A[i];
        }   
    }
    return res; 
}
