#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define tc int t; cin>>t; while(t--)

void solve()
{
    string str;
    cin>>str;
    int n=str.size();
    int ans=0;
    int temp=0;
    for(int i=0;i<n-1;i++)
    {
        if(str[i]=='1' && str[i+1]=='0') ans++;
        else if(str[i]=='0' && str[i+1]=='1') temp++;
    }
    if(temp==0) ans++;
    ans+=temp;
    cout<<ans<<endl;
    // cout<<n<<endl;
}

int main()
{
    tc
    {
        solve();
    }
    return 0;
}
