/* Problem Link: https://www.interviewbit.com/problems/reverse-integer/ */

int Solution::reverse(int A) { 
    long int retval = 0;
    while(A != 0) {
        retval  = 10*retval + A%10;
        A /= 10;
    }
    if(retval > INT_MAX || retval < INT_MIN) {
        return 0;
    }
    else {
        return retval;
    }
}
