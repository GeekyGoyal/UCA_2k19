/* Problem Link: https://www.interviewbit.com/problems/flip/ */

/* Using Kadane's Algorithm: SubString with maximum Sum */

vector<int> Solution::flip(string A) {
    int st = -1;
    int en = -1;
    int ans = -1;
    int sum = 0;
    int tst = 0;
    for(int i = 0; i < A.length(); i++) {
        if(A[i] == '0') {
            sum += 1;
        }
        else {
            sum -= 1;
        }
        if(sum >= 0) {
            if(sum > ans) {
                ans = sum;
                st = tst;
                en = i;
            }
        }
        else {
            sum = 0;
            tst = i+1;
        }
    }
    vector<int> give;
    if(ans > 0) {
        give.push_back(st+1);
        give.push_back(en+1);
    }
    return give;
}

/***** OR *****/
int flipBits(int* arr, int n) 
{
    int sum=0,c=0,aux=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            c++;
            aux = max(-1, aux-1);
        }
        else
        {
            aux = max(1, aux+1);
        }
        sum = max(sum, aux);
    }
    return c+sum;
}
