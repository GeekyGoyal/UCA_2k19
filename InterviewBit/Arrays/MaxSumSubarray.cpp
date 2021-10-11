/* Problem Link: https://www.interviewbit.com/problems/max-sum-contiguous-subarray/ */

/* Kadane's Algorithm 
*  Time Complexity: O(N) */

int Solution::maxSubArray(const vector<int> &A) {
    int n = A.size();
    int maxSum = INT_MIN, currSum = 0;
    for(int i = 0; i < n; i++) {
        currSum = currSum + A[i];
        maxSum = max(maxSum, currSum);
        if(currSum < 0) {
            currSum = 0;
        }
    }
    return maxSum;
}
