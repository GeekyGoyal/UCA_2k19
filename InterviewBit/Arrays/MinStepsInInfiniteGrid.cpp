/* Problem Link: https://www.interviewbit.com/problems/min-steps-in-infinite-grid/ 
*
* Movement is allowed in 8 directions 
* For eg: (1,4) -> (5,11)
* steps required = max(abs(x-a), abs(y-b))
* (1,4) -> (2,5) -> (3,6) -> (4,7) -> (5,8) -> (5,9) -> (5,10) -> (5,11)
* Total steps required in this example are max(abs(x-a), abs(y-b)) i.e, 7 steps */

int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int n = A.size();
    int ans = 0;
    int x = A[0], y = B[0];
    for(int i = 1; i < A.size(); i++) {
        int t1 = abs(x - A[i]);
        int t2 = abs(y - B[i]);
        ans += max(t1, t2);
        x = A[i];
        y = B[i];
    }
    return ans;
   
}
