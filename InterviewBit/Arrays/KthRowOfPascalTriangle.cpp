/* Problem Link: https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/ */


/*  Approach 1: Using Binomial Coefficient. Find ⁿc₀ t0 ⁿcₓ (x=col-1) for given row number n
*               Time Complexity : O(n²)
*               Space Complexity: O(1)
*   Approach 2: Using simple math, Multiply every previous element with (n-i)/(i+1) where i is the given row index.
*               Time Complexity : O(n)
*               Space Complexity: O(1)
*/

vector<int> Solution::getRow(int A) {
    vector<int>a;
    int n = 1;
    for(int i = 0; i <= A; i++) {
        a.push_back(n);
        n = n*(A-i)/(i+1);
    }
    return a;
}

/***** Using DP *****/

vector<int> Solution::getRow(int k) {
    vector<int>dp(k+1);
    for(int i=0;i<=k;i++){
        dp[i]=0;
    }
    dp[0]=1;
    for(int i=1;i<=k;i++){
        for(int j=min(k,i);j>=0;j--){
            dp[j]=dp[j]+dp[j-1];
        }
    }
    return dp;
}
