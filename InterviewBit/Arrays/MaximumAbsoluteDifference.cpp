/* Problem Link: https://www.interviewbit.com/problems/maximum-absolute-difference/ */

/* BruteForce or Naive Approach 
*  Time Complexity: O(N^2)  */

int Solution::maxArr(vector<int> &A) {
    int n = A.size();
    int maxm = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) { 
            int sum = abs(A[i] - A[j]) + abs(i - j);
            if(sum > maxm) {
                maxm = sum;
            }
        }
    }
    return maxm;
}


/* Optimised Approach */ 

int Solution::maxArr(vector<int> &A) {
    int n = A.size(), ans = 0;
    int max1 = INT_MIN, max2 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;
    for(int i = 0; i < n; i++) { 
       max1 = max(max1, A[i] + i);
        max2 = max(max2, A[i] - i);
        min1 = min(min1, A[i] + i);
        min2 = min(min2, A[i] - i);
    }
    ans = max(ans, max2 - min2);
    ans = max(ans, max1 - min1);
    return ans;
}

