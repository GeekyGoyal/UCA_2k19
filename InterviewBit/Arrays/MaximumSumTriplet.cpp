/* Problem Link: https://www.interviewbit.com/problems/maximum-sum-triplet/ */

// BruteForce or Naive Approach
int solve(vector<int> &A) {
    int size = A.size();
    int ans = 0;

    for(int i = 1; i < size-1; i++){
        int X = 0;
        int Y = 0;
        for(int j = 0; j < i; j++) {
            if(A[j] < A[i]) {
                X = max(X,A[j]);
            }
        }
        for(int j = i+1; j < size; j++) {
            if(A[j] > A[i]) {
                Y = max(Y, A[j]);
            }
        }
      
        if(X == 0 || Y == 0){
            continue;
        }
        int sum = X + Y + A[i];
        ans = max(sum, ans);
    }
    return ans;
}



// Optimised Approach
int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> suffix(n, 0);
    suffix[n-1] = A[n-1];
    for(int i = n-2; i >= 0; i--) {
        suffix[i] = max(A[i], suffix[i+1]);
    }
    
    set<int> s;
    s.insert(INT_MIN);
    int ans = 0;
    for(int i = 0; i < n-1; i++) {
        if(suffix[i+1] > A[i]) {
            auto it = s.lower_bound(A[i]);
            --it;
            ans = max(ans, *it + A[i] + suffix[i+1]);
            s.insert(A[i]);
        }
    }
    return ans;      
}
