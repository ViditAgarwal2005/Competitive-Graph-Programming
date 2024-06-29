class Solution {
public:

    int dijkstra(int start, int n, int k, vector<vector<pair<int, int>>>& adj)
    {
        vector<int> dis(n, 1e9);
        dis[start] = 0;
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, start});
        int ans=0;

        while(!q.empty())
        {
            int node = q.top().second;
            int cur_dis = q.top().first;
            q.pop();
            for(auto neigh:adj[node])
            {
                int child = neigh.second;
                int weight = neigh.first;
                if(dis[child] > cur_dis + weight && cur_dis + weight <=k)
                {
                    if(dis[child]==1e9) ans++;
                    dis[child] = cur_dis + weight;
                    q.push({dis[child], child});
                }
            }
        }
        // cout<<start<<" -> ";
        // for(int i=0;i<n;i++)
        // {
        //     cout<<dis[i]<<" ";
        // }
        // cout<<" => "<<ans;
        // cout<<endl;
        return ans;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            int c = edges[i][2];
            adj[a].push_back({c, b});
            adj[b].push_back({c, a});
        }
        vector<int> ans(n, 0);
        for(int i=0;i<n;i++)
        {
            ans[i] = dijkstra(i, n, distanceThreshold, adj);
        }
        int finalans=n-1;
        for(int i=n-1;i>=0;i--)
        {
            if(ans[finalans]>ans[i])
            {
                finalans = i;
            }
        }
        return finalans;
    }
};

/*
1 -> make graph
2 -> apply dijkstra for each node and make array to store reachable cities within threshold distance
3 -> find minimum from behind
*/
