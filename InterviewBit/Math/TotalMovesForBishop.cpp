/* Problem Link: https://www.interviewbit.com/problems/total-moves-for-bishop/ */

int Solution::solve(int A, int B) {
    int topLeft = min(A-1, B-1);
    int topRight = min(A-1, 8-B);
    int bottomLeft = min(8-A, B-1);
    int bottomRight = min(8-A, 8-B);
    int ans = topLeft + topRight + bottomLeft + bottomRight;
    return ans;
}
