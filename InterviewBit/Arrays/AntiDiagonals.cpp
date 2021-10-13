/* Problem Link: https://www.interviewbit.com/problems/anti-diagonals/ */

/* Approach: The sum of indexes (row index + col index) in an anti-diagonal remains the same. */

/****** Brute-Force Approach ******/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n = A.size();
    int N = 2*(n-1) + 1;//number of vectors in ans
    vector<vector<int>> ans(N);
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
            ans[i+j].push_back(A[i][j]);//sum of index values in 2d array gives the index in ans
    }
    return ans;
}

/****** Optimised Approach ******/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n = A.size();
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++) {
        int col = i, row = 0;
        vector<int> req;
        while(col >= 0) {
            req.push_back(A[row][col]);
            row++;
            col--;
        }
        ans.push_back(req);
    }
    for(int i = 1; i < n; i++) {
        int row = i, col = n-1;
        vector<int> req;
        while(row < n) {
            req.push_back(A[row][col]);
            row++;
            col--;
        }
        ans.push_back(req);
    }
    return ans;
}
