/* Problem Link: https://www.interviewbit.com/problems/sort-array-with-squares/ */

vector<int> Solution::solve(vector<int> &A) {
    int size = A.size();
    vector<int> v;
    for(int i = 0; i < size; i++) {
        v.push_back(A[i] * A[i]);
    }
    sort(v.begin(), v.end());
    return v; 
}
