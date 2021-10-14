/* Problem Link: https://www.interviewbit.com/problems/find-permutation/ */

vector<int> Solution::findPerm(const string A, int B) {
    int n = A.length();
	assert(n == B-1);
	int l = 1, r = n+1;
	vector<int> ans;
	for(int i = 0; i < n; i++) {
		(A[i] == 'I') ? ans.push_back(l++) : ans.push_back(r--);
	}
	ans.push_back(l);
	return ans;
}

/***** OR ******/

vector<int> Solution::findPerm(const string A, int B) {
    vector<int> res;
    int v = 1;
    int prev_i = 0, start = 0;
    for (int i = 0; i < A.size(); ++i) {
        prev_i = i;
        while (i < A.size() && A[i] == 'D') ++i;
        int cnt = i - prev_i + 1;
        //printf("%d %d => %d\n", prev_i, i, start);
        for (int j = 0; j < cnt; ++j) res.push_back(start+cnt-j);
        start += cnt;
    }
    if (A.back() == 'I') res.push_back(start+1);
    //for (int r : res) printf("%d\n", r);
    return res;
}
