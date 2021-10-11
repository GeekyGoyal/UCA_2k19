/* Problem Link: https://www.interviewbit.com/problems/repeat-and-missing-number-array/ */

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long int n = A.size();
    long long int arrSum = 0, sqArrSum = 0, sum = n*(n+1)/2, sqSum = n*(n+1)*(2*n+1)/6;
    for(int i = 0; i < n; i++) {
        arrSum += (long long int)A[i];
        sqArrSum += (long long int)A[i]*(long long int)A[i];
    }
    long long int diff = sum - arrSum;
    long long int add = (sqSum - sqArrSum)/diff;
    vector<int> ans;
    // Repeating
    ans.push_back((add-diff)/2);
    // Missing 
    ans.push_back((add+diff)/2);
    return ans;
}
