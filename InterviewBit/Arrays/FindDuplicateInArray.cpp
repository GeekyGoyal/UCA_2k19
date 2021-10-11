/* Problem Link: https://www.interviewbit.com/problems/find-duplicate-in-array/ */

/* Approach 1 (This Approach takes Extra Space) */

int Solution::repeatedNumber(const vector<int> &A) {
    vector<int> res;
    res = A;
    sort(res.begin(), res.end());
    for(int i = 0; i < res.size(); i++) {
        if(res[i] == res[i+1]) {
            return res[i];
        }
    }
    return -1;
}

/* Approach 2 (Floyd's Cycle or Floyd's Tortoise-Hare Algorithm)
* Find Duplicate number in an immutable array */

int Solution::repeatedNumber(const vector<int> &A) {
    int slow = A[0];
    int fast = A[0];
    do {
        slow = A[slow];
        fast = A[A[fast]];
    }
    while(slow != fast) {
        slow = A[slow];
        fast = A[fast];
    }
    return slow;
}



