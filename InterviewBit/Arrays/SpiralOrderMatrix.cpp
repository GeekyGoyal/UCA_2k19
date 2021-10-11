/* Problem Link: https://www.interviewbit.com/problems/spiral-order-matrix-ii/ */

/****** Solution 1 ******/
vector<vector<int> > Solution::generateMatrix(int n) {
    // Direction arrays
    // index 0  i += 0  j += 1 : Go Right
    // index 1  i += 1  j +=0 : Go Down
    // index 2  i += 0  j -=1 : Go Left
    // index 3  i -= 1  j += 0 : Go Up
    int row[] = {0,1,0,-1};
    int col[] = {1,0,-1,0};

    // Square matrix to store answer spiral matrix
    vector<vector<int>> ans(n,vector<int>(n,0));
    // Corner case
    if(n <= 0) {
        return ans;
    }
    
    // Number of elements in square matrix; 1 is being subtracted as ans[0][0] is being set before loop
    int count = (n*n)-1;
    int i = 0, j = 0;

    // Start by going right
    int index = 0;
    
    // The value to be written
    int val = 1;
    ans[0][0] = 1;
    
    while(count--) {
        // Reached corner in matrix
        if((i + row[index] < 0) || (i + row[index] == n) || (j + col[index] < 0) || (j + col[index] == n)) {
            index++;
        }
        // Reached a point where if we go further in the same direction then a value will be overwritten
        // Hence change direction
        else if(ans[i+row[index]][j+col[index]] != 0) {
            index++;
        }
        
        // If index of direction exceeds 3, set it back to 0
        if(index==4) {
            index=0;
        }
        i += row[index];
        j += col[index];
        ans[i][j] = ++val;
    }
    return ans;
}


/****** Solution 2 ******/
vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int> > res(A);
    for(int i=0; i<A; i++) res[i].resize(A);
    
    int top = 0, bottom = A-1, left = 0, right = A-1, n = 1;
    while(n <= A*A){
        for(int i=left; i<=right; i++) res[top][i] = n++;
        top++;
        for(int i=top; i<=bottom; i++) res[i][right] = n++;
        right--;
        for(int i=right; i>=left; i--) res[bottom][i] = n++;
        bottom--;
        for(int i=bottom; i>=top; i--) res[i][left] = n++;
        left++;
    }
    return res;
}
