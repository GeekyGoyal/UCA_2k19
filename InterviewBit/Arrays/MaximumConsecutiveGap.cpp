/* Problem Link: https://www.interviewbit.com/problems/maximum-consecutive-gap/ */


/* Concept of BUCKETING and PIGEON HOLE PRINCIPLE
DRY RUN: Take a array: [2, 8, 10, 20, 22]
n=5
max=22
min=2
delta = (max-min)/(n-1)= (22-2)/(5-1)=5
no. of buckets = n-1 = 4

index=(v[i] - minval)/delta
bucket indexes
(2-2)/5=0
(8-2)/5=1
(10-2)/5=1
(20-2)/5=3
(22-2)/5=4
bmin  elements   8      INT_MAX   INT_MAX   20
bmax elements   10    INT_MIN    INT_MIN    20

didn't filled max and min elements in buckets

 2   |----8---------10----| |---------------------|   |-----------------------| |----20--------|  22
           bucket 0               bucket 1               bucket 2          bucket 3
ans = 20-10 = 10

*/



int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    int maxVal = *max_element(A.begin(),A.end());
    int minVal = *min_element(A.begin(),A.end());
    vector<int> bMax(n-1, INT_MIN);
    vector<int> bMin(n-1, INT_MAX);
    float delta = (float)(maxVal-minVal)/(float)(n-1);
    for(int i = 0; i < n; i++) {
        if(minVal == A[i] || maxVal == A[i]) {
            continue;
        }
        int index = (A[i]-minVal)/delta;
        bMax[index] = max(bMax[index], A[i]);
        bMin[index] = min(bMin[index], A[i]);
    }
        int prev = minVal;
        int ans = 0;
        for(int i = 0; i < n-1; i++) {
            if(bMin[i] == INT_MAX) {
                continue;
            }
            ans = max(ans, bMin[i]-prev);
            prev = bMax[i];
        }
        ans = max(ans, maxVal-prev);
        return ans;
}
