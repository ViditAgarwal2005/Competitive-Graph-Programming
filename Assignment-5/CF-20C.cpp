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

void dijkstra(int start, int n, vector<vector<pair<ll, int>>>& adj)
{
    vector<ll> dis(n, 1e18);
    vector<int> parent(n, -1);
    priority_queue<pair<ll,int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    // pairs are {distance, node} type

    dis[start] = 0;
    q.push({0, start});

    while(!q.empty())
    {
        int node = q.top().second;
        q.pop();
        for(auto neighbor:adj[node]) // neghbor is pair => 1st is weight, 2nd is node
        {
            int child = neighbor.second;
            ll weight = neighbor.first; // node to child weight
            if(dis[child] > dis[node] + weight)
            {
                dis[child] = dis[node] + weight ;
                parent[child] = node;
                q.push(neighbor);
            }
        }
    }
    // vout(dis);
    if(dis[n-1]==1e18)
    {
        cout<<-1<<endl;
        return ;
    }
    vector<int> ans;
    for(int i=n-1;i!=0;i=parent[i])
    {
        ans.push_back(i+1);
    }
    ans.push_back(1);
    reverse(all(ans));
    vout(ans);

    return ;
}

void solve()
{
    int n, m;
    cin>>n>>m;

    vector<vector<pair<ll, int>>> adj(n);

    for(int i=0;i<m;i++)
    {
        int a, b;
        ll c;
        cin>>a>>b>>c;
        a--; b--;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    dijkstra(0, n, adj);
    
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
