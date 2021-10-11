/* Problem Link: https://www.interviewbit.com/problems/maximum-sum-square-submatrix/ */

/* Approach 1 */
int Solution::solve(vector<vector<int> > &A, int B) {
    int r = A.size(), c = A[0].size();
    int sum = INT_MIN;
    vector<vector<int>> dp(r+1, vector<int>(c+1,0));
    for(int i = 1; i < dp.size(); i++) {
        for(int j = 1; j < dp[0].size(); j++) {
            dp[i][j] = A[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    for(int i = 1; i < dp.size(); i++) {
        for(int j = 1; j < dp[0].size(); j++) {
            if(i-B >= 0 && j-B >= 0) {
                sum = max(sum, dp[i][j] - dp[i-B][j] - dp[i][j-B] + dp[i-B][j-B]);
            }
        }
    }
    return sum;
}

/* Approach 2 */
int maxsum(vector<int>&row,int B){
    int n = row.size();
    int i=0,j=0;
    int su  = 0;
    int ans = INT_MIN;
    while(j<n){
        su+=row[j];
        if(j-i+1==B){
            ans = max(ans,su);
            su -= row[i];
            i++;
        }
        j++;
    }
    return ans;
}

int Solution::solve(vector<vector<int> > &A, int B) {
    int n = A.size();
    int ans = INT_MIN;
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++)
            A[i][j] += A[i-1][j];
    }
    for(int i=0;i<n-B+1;i++){
        vector<int>row(n,0);
        for(int j=0;j<n;j++){
            if(i==0){
                row[j] = A[i+B-1][j];
            }
            else 
                row[j] = A[i+B-1][j] - A[i-1][j];
        }
        int temp = maxsum(row,B);
        ans = max(ans,temp);
    }
    return ans;
}
