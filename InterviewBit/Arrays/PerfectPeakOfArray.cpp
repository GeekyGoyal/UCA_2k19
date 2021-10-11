/* Problem Link: interviewbit.com/problems/perfect-peak-of-array/ */

int Solution::perfectPeak(vector<int> &A) {
    int size = A.size();
    vector<int> x(size);
    vector<int> y(size);

    x[0] = A[0];
    for(int i=1; i < size; i++) {
        x[i] = max(x[i-1], A[i]);
    }
    y[size-1] = A[size-1];
    for(int j = size-2; j >= 0; j--) {
        y[j] = min(y[j+1], A[j]);
    }

    for(int k = 1; k <= size-2; k++) {
        if(x[k-1] < A[k] && A[k] < y[k+1]) {
            return 1;
        }
    }
return 0;
}


// Another Approach 
int Solution::perfectPeak(vector<int> &A) {
    unordered_set<int> a;
    int max = A[0];
    for(int i=1;i<A.size();i++) {
        if(A[i]>max) {
            max = A[i];
            a.insert(i);
        }
    }
    int min = A[A.size()-1];
    for(int i=A.size()-2;i>=0;i--) { 
        if(A[i]<min) {
            min = A[i];
            if(a.find(i)!= a.end()) {
                return 1;
            }
        }
    }  
return 0;
}
