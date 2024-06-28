#define ll long long

int dijkstra(int start, int end, int n, vector<vector<pair<int, int>>>& adj)
{
    vector<ll> dis(n+1, 1e9);
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    // pairs are {distance, node} type
    
    dis[start] = 0;
    q.push({0, start});

    while(!q.empty())
    {
        int node = q.top().second;
        int cur_dis = q.top().first;
        q.pop();
        for(auto neighbor:adj[node]) // neghbor is pair => 1st is weight from node to child, 2nd is child
        {
            int child = neighbor.second;
            ll weight = neighbor.first; // node to child weight
            if(dis[child] > cur_dis + weight)
            {
                dis[child] = cur_dis + weight ;
                q.push({dis[child], child});
            }
        }
    }
    return dis[end];
}

int Solution::solve(int n, vector<vector<int> > &B, int start, int end, vector<vector<int> > &E) {
    
    vector<vector<pair<int, int>>> adj(n+1);
    for(int i=0;i<B.size();i++)
    {
        int a = B[i][0];
        int b = B[i][1];
        int c = B[i][2];
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    
    // DIJKSTRA
    int ans=1e9;
    for(int i=0;i<E.size();i++)
    {
        int a = E[i][0];
        int b = E[i][1];
        int c = E[i][2];
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
        int tempans = dijkstra(start, end, n, adj);
        ans = min(ans, tempans);
        adj[a].pop_back();
        adj[b].pop_back();
    }
    if(ans==1e9) return -1;
    return ans;
    
}
