/* Problem Link: https://www.interviewbit.com/problems/wave-array/ */

/*** O(N LogN) ***/

vector<int> Solution::wave(vector<int> &A) {
    int size = A.size();
    sort(A.begin(), A.end());
    for(int i = 1; i < size; i+=2) {
            swap(A[i], A[i-1]);
    }
    return A;
}
