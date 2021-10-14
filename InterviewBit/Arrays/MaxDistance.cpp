/* Problem Link: https://www.interviewbit.com/problems/max-distance/ */

int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    vector<int> maxFromEnd(n+1, INT_MIN);
    for(int i = A.size() - 1; i >= 0; i--) {
        maxFromEnd[i] = max(maxFromEnd[i+1], A[i]);
    }
    int result = 0;
    for(int i = 0; i < A.size(); i++) {
        int low = i + 1, high = A.size() - 1, ans = i;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(A[i] <= maxFromEnd[mid]) {
                ans = max(ans, mid);
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        result = max(result, ans - i);
    }
    return result;
}

/***** OR *****/

int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    if(n == 0) return 0;
    int p[n];
    p[n-1] = A[n-1];
    for(int i = n - 2; i >= 0; i--)
        p[i] = max(p[i+1] , A[i]);
    int i = 0 , j = 0 , ans = 0;
    while(i < n){
        while(j < n && p[j] >= A[i]){
            ans = max(ans , j - i);
            j++;
        }
        i++;
    }
    return ans;
}

/***** OR *****/

int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    vector<pair<int,int>> v;
    
    for(int i = 0; i < n; i++) {
        v.push_back({A[i],i});
    }
    sort(v.begin(),v.end());
    int ans = 0;
    int rmax = v[n-1].second;
    
    for(int i = n-2; i >= 0; i--) {
        ans = max(ans, rmax-v[i].second);
        rmax = max(rmax, v[i].second);
    }
    return ans;
}
