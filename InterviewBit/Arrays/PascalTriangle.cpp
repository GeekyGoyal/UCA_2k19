/* Problem Link: https://www.interviewbit.com/problems/pascal-triangle/ */

vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> ans;
    for(int i = 0; i < A; i++) {
        vector<int> row(i+1);
        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i) { 
                row[j] = 1;
            }
            else { 
                row[j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
        ans.push_back(row);
    }
    return ans;
}
