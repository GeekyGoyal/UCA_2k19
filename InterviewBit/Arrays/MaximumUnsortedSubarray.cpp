/* Problem Link: https://www.interviewbit.com/problems/maximum-unsorted-subarray/ */

vector<int> Solution::subUnsort(vector<int> &A) {
    int n = A.size();
    int s = -1, e = -1;
    for(int i = 0; i < n-1; i++) {
        if(A[i] > A[i+1]) {
            s = i;
            break;
        }
    }
    vector<int> ans;
    if(s == -1) {
        ans.push_back(s);
        return ans;
    }
    for(int i = n-1; i >= 0; i--) {
        if(A[i-1] > A[i]) {
            e = i;
            break;
        }
    }
    int maxVal = INT_MIN, minVal = INT_MAX;
    for(int i = s; i <= e; i++) {
        minVal = min(minVal, A[i]);
        maxVal = max(maxVal, A[i]);
    }
    for(int i = 0; i <= s-1; i++) {
        if(A[i] > minVal) {
            s = i;
            break;
        }
    }
    for(int i = n-1; i >= e+1; i--) {
        if(A[i] < maxVal) {
            e = i;
            break;
        }
    }
    ans.push_back(s);
    ans.push_back(e);
    return ans;
}
