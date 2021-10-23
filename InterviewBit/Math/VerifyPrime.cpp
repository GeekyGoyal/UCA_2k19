/* Problem Link: https://www.interviewbit.com/problems/verify-prime/ */

int Solution::isPrime(int A) {
    if(A < 2) {
        return 0;
    }
    if(A == 2) {
        return 1;
    }
    if(A % 2 == 0) {
        return 0;
    }              
    for(int i = 3; i <= sqrt(A); i = i + 2) {
        if(A % i == 0) {
            return 0;
        }
    }
    return 1;
}
