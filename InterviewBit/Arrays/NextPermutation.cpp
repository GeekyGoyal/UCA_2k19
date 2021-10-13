/* Problem Link: https://www.interviewbit.com/problems/next-permutation/ */

/***** Using C++ STL (In-Built Library Function) *****/

#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int t,n;
	cin >> t;
	while(t--)
	{
		cin>>n;
		int arr[n];
		for(int i = 0; i < n; i++)
		cin >> arr[i];
    next_permutation(arr, arr+n);
    for(int i = 0; i < n; i++) { 
      cout<<arr[i]<<" ";
    }
    cout<<endl;
	}
	return 0;
}


/***** Without STL Function *****/

/* Approach: 
* Example: 1 5 8 4 7 6 5 3 1
* The array is strictly decreasing from the number 7. So, Lets call the number 7 as Y,
* the number before Y as X (in this case, 4 is X)
* And the number just greater than X as Z (in this case 5 is Z).
* Swap X with Z. So now our array looks like this: 1 5 8 5 7 6 4 3 1
* Now, Just reverse the Strictly decreasing part of the array (That is the numbers from Y till the end)
* Now, we got our NEXT PERMUTATION. i.e, 1 5 8 5 1 3 4 6 7
*/

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapWith(int num, vector<int>& A, int i) {
    int min = A[i];
    int j = i, index = i;
    for(j = i; j < A.size(); j++) {
        if(min > A[j] && A[j] > A[num]) {
            index = j;
            min = A[j];
        }
    }
    swap(A[index], A[num]);
}

bool myFun(int i, int j) {
    return i > j;
}

vector<int> Solution::nextPermutation(vector<int> &B) {
    vector<int> A = B;
    if(A.size() == 0 || A.size() == 1) {
        return A;
    }
    
    int flag = 0;
        
    for(int i = A.size()-1; i > 0; i--) {
        if(A[i] > A[i-1]) {
            swapWith(i-1, A, i);
            sort(A.begin()+i, A.end());
            flag = 1;
            break;
        }
    }
    
    if(flag == 0) {
        sort(A.begin(), A.end());
    }
    return A;
}

// OR 

vector<int> Solution::nextPermutation(vector<int> &A) {
    vector<int> ans;
    int i = A.size()-2;
    while(i >= 0) {
        if(A[i] < A[i+1]) {
            break;
        }
        --i;
    }
    if(i == -1) {
        reverse(A.begin(), A.end());
        ans = A;
        return ans;
    }
    int j = A.size()-1;
    while(j > i) {
        if(A[j] > A[i]) {
            break;
        }
        --j;
    }
    swap(A[i], A[j]);
    reverse(A.begin() + i + 1, A.end());
    ans = A;
    return ans;
}
