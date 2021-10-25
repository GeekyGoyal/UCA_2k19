/* Problem Link: https://www.interviewbit.com/problems/greatest-common-divisor/ */

/* BRUTEFORCE APPROACH: Keep on iterating from 1 to min(a, b) and find the greatest number that divides both a and b. (Inefficient Approach)
*
* EUCLID'S ALGORITHM: 
* RECURSIVE CASE: gcd(a, b) = gcd(b, a%b) 
* BASE CASE: gcd(a,0) = a
*/

int Solution::gcd(int A, int B) {
    return B == 0 ? A : gcd(B, A % B);
}
