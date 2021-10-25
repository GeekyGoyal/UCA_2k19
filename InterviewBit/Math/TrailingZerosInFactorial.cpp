/* Problem Link: https://www.interviewbit.com/problems/trailing-zeros-in-factorial/ */

/* A trailing zero is always produced by prime factors 2 and 5. If we can count the number of 5s and 2s, our task is done.
*  Trailing 0s in n! = Count of 5s in prime factors of n!
*                    = floor(n/5) + floor(n/25) + floor(n/125) + ....
*/               


int Solution::trailingZeroes(int A) {
    // Negative Number Edge Case
     if (A < 0) 
        return -1;
 
    // Initialize result
    int count = 0;
 
    // Keep dividing n by powers of 5 and update count
    for (int i = 5; A / i >= 1; i *= 5)
        count += A / i;
 
    return count;
}
