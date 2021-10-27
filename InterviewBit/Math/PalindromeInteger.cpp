/* Problem Link: https://www.interviewbit.com/problems/palindrome-integer/ */

// BruteForce Approach
int Solution::isPalindrome(int A) {
    int temp = A;
    int retval = 0;
    while(A > 0) {
        retval  = 10*retval + A%10;
        A /= 10;
    }
    if(temp == retval) {
        return true;
    }
    else {
        return false;
    }
}

// Approach 2
int Solution::isPalindrome(int A) {
    string s = to_string(A);
    for(int i = 0; i < s.length(); i++) {
        if(s[i] != s[s.length()-1-i]) {
            return false;
        }
    }
    return true;
}
