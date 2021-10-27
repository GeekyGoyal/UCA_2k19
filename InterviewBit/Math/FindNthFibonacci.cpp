/* Problem Link: https://www.interviewbit.com/problems/find-nth-fibonacci/ */

// USING MATRIX EXPONENTIATION 

/* If we n times multiply the matrix M = {{1, 1},{1, 0}} to itself (in other words calculate power(M, n )), then we get the (n+1)th Fibonacci number as the element at row 
* and column (0, 0) in the resultant matrix. 
* 
* Time Complexity: O(LogA)
* Extra Space: O(LogA) if we consider the function call stack size, otherwise O(1).*/

long long M[2][2] = {{1, 1}, {1, 0}};
long long m = 1000000007;

void multiply(long long A[2][2], long long B[2][2]) {
    long long a = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    long long b = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    long long c = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    long long d = A[1][0] * B[0][1] + A[1][1] * B[1][1];
    
    a %= m;
    b %= m;
    c %= m;
    d %= m;
    
    A[0][0] = a;
    A[0][1] = b;
    A[1][0] = c;
    A[1][1] = d;
}

void power(long long F[2][2], long long n) {
    if(n == 0) { 
        return;
    }
    if(n == 1) { 
        return;
    }
    
    if(n % 2 == 0) {
        power(F, n/2);
        multiply(F, F);
    }
    else {
        power(F, n/2);
        multiply(F, F);
        multiply(F, M);
    }
}

int Solution::solve(int A) {
    long long ans = 0;
    long long F[2][2] = {{1, 1}, {1, 0}};
                   
    power(F, A-2);
    
    ans = F[0][0] + F [0][1];
    ans %= m;
    return ans;
}