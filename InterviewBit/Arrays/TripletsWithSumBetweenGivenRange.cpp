/* Problem Link: https://www.interviewbit.com/problems/triplets-with-sum-between-given-range/ */

int Solution::solve(vector<string> &A) {
    sort(A.begin(), A.end());
    int size = A.size();
    int i = 0;
    int j = A.size()-1;
    while(j-i >= 2) {
        int mid = (i + j)/2;
        double a = stof(A[i]);
        double b = stof(A[j]);
        double c = stof(A[mid]);
        double sum = a + b + c;
        if(sum > 2) {
            j--;
        }
        else if(sum < 1) {
            i++;
        }
        else {
            return 1;
        }
    }
    return 0;
}
