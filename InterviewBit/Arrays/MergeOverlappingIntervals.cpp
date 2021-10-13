/* Problem Link: https://www.interviewbit.com/problems/merge-overlapping-intervals/ */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool checkA(Interval a, Interval b) {
    return a.end < b.end;
}

vector<Interval> Solution::merge(vector<Interval> &A) {
    sort(A.begin(), A.end(), checkA);
    for(int i = A.size()-1; i >= 1; i--) {
        if(A[i].start <= A[i-1].end) {
            int small = min(A[i-1].start, A[i].start);
            int large = max(A[i].end, A[i-1].end);
            Interval temp = {small, large};
            A.erase(A.begin() + i- 1);
            A.erase(A.begin() + i - 1);
            A.insert(A.begin() + i - 1, temp);
        }
    }
    return A;    
}


