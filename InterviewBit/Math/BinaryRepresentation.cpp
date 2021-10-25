/* Problem Link: https://www.interviewbit.com/problems/binary-representation/ */

string Solution::findDigitsInBinary(int A) {
    if(A == 0) { 
        return "0";
    }

    string result = "";
    
    while (A != 0) {
        result += A % 2 + '0';
        A /= 2;
    }
    reverse(result.begin(), result.end());
    return result;
}

