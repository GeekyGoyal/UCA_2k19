/* Problem Link: https://www.interviewbit.com/problems/pick-from-both-sides/ */

int Solution::solve(vector<int> &A, int B) {
    int size = A.size();
    int res = 0, currSum;
    for(int i = 0; i < B; i++) {
        res += A[i];
    }
    currSum = res;
    for(int i = 0; i < B; i++) {
        currSum = currSum - A[B-1-i] + A[size-1-i];
        res = max(res, currSum);
    }
    return res;
}
