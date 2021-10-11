/* Problem Link: https://www.interviewbit.com/problems/largest-number/ */

/************* Approach 1 *************/
bool comp(int a, int b) {
    string x, y;
    x = to_string(a);
    x += to_string(b);
    y = to_string(b);
    y += to_string(a);
    if(y > x) {
        return true;
    }
    else { 
        return false;
    }
}

string Solution::largestNumber(const vector<int> &A) {
    vector<int> vs;
    for(int i = 0; i < A.size(); i++) {
        vs.push_back(A[i]);
    }
    sort(vs.begin(), vs.end(), comp);
    string ans = "";
    for(int i = A.size()-1; i >= 0; i--) {
        ans += to_string(vs[i]);
    }
    if(ans.length() == 0 || ans[0] == '0') {
        ans = '0';
    }
    return ans;
}

/************* Approach 2 *************/
bool mycompare(string a, string b){
    string ab=a.append(b);
    string ba=b.append(a);
    return ab.compare(ba)>0?1:0;
}

string Solution::largestNumber(const vector<int> &A) {
    vector<string> arr(A.size());
    int count=0;
    for(int i=0; i<A.size(); i++){
        if(A[i]==0)
            count++;
        arr[i]=to_string(A[i]);
    }
    if(count==A.size())
        return "0";
    sort(arr.begin(),arr.end(),mycompare);
    string ans=arr[0];
    for(int i=1; i<arr.size(); i++)
        ans=ans+arr[i];
    return ans;
    
}
