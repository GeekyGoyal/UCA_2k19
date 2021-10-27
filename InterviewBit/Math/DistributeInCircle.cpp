/* Problem Link: https://www.interviewbit.com/problems/distribute-in-circle/ */

/* Solution Approach: We check if the number of items to be distributed is greater than our remaining positions in current cycle of circle or not.
*
* If yes, then we simply return A + C – 1 (We distribute items in same cycle starting from C). Else we compute number of remaining items after completing current cycle and 
* return mod of remaining items. 
* 
*/

int Solution::solve(int A, int B, int C) {
    return (C + (A - 1) % B) % B;
}
