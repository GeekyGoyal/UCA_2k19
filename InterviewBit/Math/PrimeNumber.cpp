/* Problem Link: https://www.interviewbit.com/problems/prime-numbers/ */

/* PRIME SIEVE 
* 
* NOTE: ALL EVEN NUMBERS ARE NOT PRIME. SO, ALL EVEN NUMBERS CAN BE SKIPPED.
*
* TIME COMPLEXITY: O(N LOG LOG N) */

vector<int> Solution::sieve(int A) {
    int P[1000005] = {0};

    // First Mark all Odd Numbers as Prime
    for(int i = 3; i <= 1000000; i += 2) {
        P[i] = 1;
    }

    // Sieve
    for(long long int i = 3; i <= 1000000; i += 2) {
        // if the current number is not marked, It is Prime
        if(P[i] == 1) {
            // Mark all the multiples of i as Not Prime
            for(long long int j = i*i; j <= 1000000; j = j + i) {
                P[j] = 0;
            }
        }
    }

    // Special Case
    P[2] = 1;
    P[1] = P[0] = 0;

    vector<int> ans;
    // Print Primes upto Given Range
    for(int i = 0; i <= A; i++) {
        if(P[i] == 1) {
            ans.push_back(i);
        }
    }
    return ans;
}
