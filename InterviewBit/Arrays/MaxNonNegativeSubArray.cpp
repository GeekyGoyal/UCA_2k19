/* Problem Link: https://www.interviewbit.com/problems/max-non-negative-subarray/ */

vector<int> Solution::maxset(vector<int> &A) {
    vector<int> ans;
    int size = A.size();
    long long int sum = 0, maxSum = 0, left = 0, right = 0, aleft = -1, aright = -1;
    for(int i = 0; i < size; i++) {
        if(A[i] >= 0) {
            sum += A[i];
            if(sum > maxSum || (sum == maxSum && aright - aleft < right - left)) {
                maxSum = sum;
                aleft = left;
                aright = right;
            }
        }
        else {
            sum = 0;
            left = i + 1;
        }
        right++;
    }
    if(aleft == -1) {
        return ans;
    }
    for(int i = aleft; i <= aright; i++) {
        ans.push_back(A[i]);
    }
    return ans;
}
