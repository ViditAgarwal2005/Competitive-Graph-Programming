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
#define vout(p) for(auto i:p) cout << i << " "

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
    int n, k, q;
    cin>>n>>k>>q;
    vi a(k+1,0), b(k+1,0); // a is distance and b is time
    for(int i=1;i<=k;i++) cin>>a[i];
    for(int i=1;i<=k;i++) cin>>b[i];
    // vout(a); cout<<endl;
    // vout(b); cout<<endl;

    while(q--)
    {
        ll d;
        cin>>d;
        int l=0, r=k, mid=-1;
        
        while(l<=r)
        {
            mid  = l +(r-l)/2;
            if(a[mid]<=d && (a[mid+1]>d || mid==k-1))
            {
                break;
            }
            else if(a[mid]>d)
            {
                r=mid-1;
            }
            else if(a[mid]<d)
            {
                l=mid+1;
            }
        }
        // double velocity=(a[mid+1]-a[mid])*1.00/(b[mid+1]-b[mid]);
        // ll temp = (d-a[mid])/velocity;
        ll ans = b[mid] + ( (d-a[mid])*(b[mid+1]-b[mid]) ) / ( a[mid+1]-a[mid] );
        // cout<<mid<<" "<<velocity<<" "<<ans<<" "<<temp<<" "<<d<<" "<<a[mid]<<endl;
        cout<<ans<<" ";
    }
    cout<<endl;
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
    
