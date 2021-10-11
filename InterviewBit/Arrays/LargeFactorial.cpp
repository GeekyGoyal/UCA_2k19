/* Problem Link: https://www.interviewbit.com/problems/large-factorial/ */

void multiply(vector<long long int> &ans, int num) {
	int carry = 0;
	for(int i = 0; i < ans.size(); i++) {
		long long int prod = ans[i] * num + carry;
		carry = prod/10;
		ans[i] = prod%10;
	}
	while(carry) {
		ans.push_back(carry%10);
		carry /= 10;
	}
}
string Solution::solve(int n) {
    vector<long long int> ans;
	ans.push_back(1);
	for(int i = 2; i <= n; i++) {
		multiply(ans, i);
	}
	reverse(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i];
	}
	cout << endl;
}
