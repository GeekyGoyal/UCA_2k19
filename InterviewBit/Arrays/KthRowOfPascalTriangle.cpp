/* Problem Link: https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/ */

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
