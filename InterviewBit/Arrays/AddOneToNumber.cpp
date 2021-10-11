/* Problem Link: https://www.interviewbit.com/problems/add-one-to-number/ */

vector<int> Solution::plusOne(vector<int> &A) {
    int size = A.size();
    reverse(A.begin(), A.end());
    vector<int> ans;
    int carry = 0;
    int val = A[0] + 1;
    carry = val/10;
    ans.push_back(val%10);
    for(int i = 1; i < size; i++) {
        val = A[i] + carry;
        carry = val/10;
        ans.push_back(val%10);
    }
    while(carry) {
        // append the carry 
        ans.push_back(carry%10);
        carry = carry/10;
    }
    // reverse the ans vector
    reverse(ans.begin(), ans.end());

    // remove the leading zeros
    vector<int> result;
	int i = 0;
	while(ans[i] == 0) {
		i++;
	}
	for(; i < ans.size(); i++) {
		result.push_back(ans[i]);
	}
	return result;
}
