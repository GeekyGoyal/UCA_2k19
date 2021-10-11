/* Problem Link: https://www.interviewbit.com/problems/minimum-lights-to-activate/ */

int Solution::solve(vector<int> &A, int B) {
    int bulb = -1, i = 0, count = 0;
    while(i < A.size()) {
        int j = i;
        while(j < A.size() && j-i < B) {
            if(A[j]) bulb = j;
            j++;
        }
        if(bulb == -1) {
             return -1;
        }
        count++; 
        i = bulb;
        bulb = -1;
        j = i+1;
        while(j < A.size() && j-i<B) {
            if(A[j]) bulb = j;
            j++;
        }
        i = j;
    }
    return count;
}
