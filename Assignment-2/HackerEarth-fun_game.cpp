#include<bits/stdc++.h>
using namespace std;

// I DID NOT UNDERSTAND WHY IS THIS A STACK QUESTION. THIS CAN BE SOLVED VIA 2 POINTER APPROACH.

vector<int> funGame (vector<int> arr) {
   // Write your code here
    // stack<int> s1, s2;
    int n =arr.size();
    vector<int> ans;
    int l=0, r=n-1;
    while(l<n && r>=0)
    {
        if(arr[l]>arr[r])
        {
            ans.push_back(1);
            r--;
        }
        else if(arr[l]<arr[r])
        {
            ans.push_back(2);
            l++;
        }
        else if(arr[l]==arr[r])
        {
            ans.push_back(0);
            l++; r--;
        }
    }
    return ans;

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i_arr=0; i_arr<n; i_arr++)
    {
    	cin >> arr[i_arr];
    }

    vector<int> out_;
    out_ = funGame(arr);
    cout << out_[0];
    for(int i_out_=1; i_out_<out_.size(); i_out_++)
    {
    	cout << " " << out_[i_out_];
    }
}
