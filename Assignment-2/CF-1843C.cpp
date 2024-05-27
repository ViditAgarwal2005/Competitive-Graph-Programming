#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define testcase int t; cin>>t; while(t--)

#define fori(i,n) for(int i=0;i<n;i++)
#define rfor(i,n) for(int i=n-1;i>=0;i--)
#define foran(i,a,n) for(int i=a;i<n;i++)

#define vi vector<int>
#define vll vector<ll>
#define all(v) v.begin(), v.end()
#define vin(p) for(auto &i:p) cin >> i
#define vout(p) for(auto i:p) cout << i << " "; cout<<endl

int gcd(int a, int b)
{
    while (b)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int isprime(int num)
{
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;
    for (int i = 5; i <= (int)sqrt(num); i += 6)
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    return 1;
}

ll a_power_b(ll a, ll b,ll mod)
{
    ll ans=1;
    if(b==0) return 1;
    if(a==0) return 0; if(a==1) return 1;
    while(b>0)
    {
        if(b&1)
        {
            ans = ans* a % mod;
        }
        a = a*a %mod;
        b>>=1;
    }
    return ans%mod;
}

void solve()
{
    ll n;
    cin>>n;
    ll ans=2*n-1;
    while(n!=1)
    {
        // cout<<n<<" ";
        ans-= (n&1);
        n = n>>1;
    }
    // cout<<endl;
    cout<<ans<<endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);

    testcase
    {
        solve();
    }

    return 0;
}
