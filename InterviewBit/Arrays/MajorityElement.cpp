/* Problem Link: https://www.interviewbit.com/problems/n3-repeat-number/ */

int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    // Boyer Moore's Voting Algorithm
    int num1 = -1, num2 = -1, cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++) {
        if(A[i] == num1) {
            cnt1++;
        }
        else if(A[i] == num2) {
            cnt2++;
        }
        else if(cnt1 == 0) {
            num1 = A[i];
            cnt1 = 1;
        }
        else if(cnt2 == 0) {
            num2 = A[i];
            cnt2 = 1;
        }
        else {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0;
    cnt2 = 0;
    for(int i = 0; i < n; i++) {
        if(A[i] == num1) {
            cnt1++;
        }
        if(A[i] == num2) {
            cnt2++;
        }
    }
    if(cnt1 > n/3) {
        return num1;
    }
    else if(cnt2 > n/3) {
        return num2;
    }
    else {
        return -1;
    }
}
