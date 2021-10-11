/* Problem Link: https://www.interviewbit.com/problems/max-min-05542f2f-69aa-4253-9cc7-84eb7bf739c4/ */

int Solution::solve(vector<int> &A) {
    int n = A.size();
    sort(A.begin(), A.end());
    int sum = A[0] + A[n-1];
    return sum;
}
