#include<bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE 
#define IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define time  cout << "\n"; auto end = chrono::steady_clock::now();auto diff = end - start; cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
#else
#define IO 
#define time
#endif
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define testcase int t; cin>>t; while(t--)

#define fori(i,n) for(int i=0;i<n;i++)
#define rfor(i,n) for(int i=n-1;i>=0;i--)
#define foran(i,a,n) for(int i=a;i<n;i++)

#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define vpii vector<pair<int, int>>
#define all(v) v.begin(), v.end()
#define vin(p) for(auto &i:p) cin >> i
#define vout(p) for(auto i:p) cout << i << " "; cout<<endl

auto start = chrono::steady_clock::now();

void solve()
{
    int n;
    cin>>n;
    vi v(n);
    vin(v);

    vi height(n+1, 0);
    for(int i=1;i<=n;i++)
    {
        fori(j, n)
        {
            if(v[j]==i)
            {
                height[i] = -1;
            }
        }
    }
    // vout(v);
    // for(int i=1;i<=n;i++) cout<<height[i]<<" ";
    // cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(height[j]==i && v[j-1]!=-1)
            {
                // cout<<"hello"<<endl;
                height[v[j-1]] = height[j] + 1;
                // vout(height);
            }
        }
    }
    // for(int i=1;i<=n;i++) cout<<height[i]<<" ";
    // cout<<endl;
    
    cout<<1+*max_element(all(height))<<endl;
    
    return ;
}

int main()
{
    IO;
    fastio;

    // testcase
    {
        solve();
    }
    time

    return 0;
}
