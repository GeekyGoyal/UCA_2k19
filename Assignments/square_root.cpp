/** Program which computes the square root of a number without any inbuilt

* @Aparna Goyal, 1911981092, 18/07/2021

* Binary Search in a Monotonic Search Space */

#include <iostream>
using namespace std;
float square_root(int n, int p) {
    int s = 0;
    int e = n;
    float ans = -1;
    while(s <= e) {
        int mid = (s+e) >> 1;
        //to check if the number is perfect square
        if(mid*mid == n) {
            return mid;
        } 
        if(mid*mid < n) {
            ans = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }

    //Floating part using Bruteforce
    float inc = 0.1;
    for(int times = 1; times <= p; times++) {
        while(ans*ans <= n) {
            ans = ans + inc;
        }
        ans = ans - inc;   //overshoot the value
        inc =  inc/10;
    }
    return ans;
}

int main() {
    int n, p;
    cin >> n >> p;
    cout << square_root(n,p) << endl;
    return 0;
}
