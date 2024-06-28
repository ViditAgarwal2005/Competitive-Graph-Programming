class Solution {
public:
    int dijkstra(int start, int n, int k, int end, vector<vector<pair<int, int>>>& adj)
    {
        vector<int> price(n, 1e9);
        vector<int> stops(n, 0);
        // priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        queue<pair<int, int>> q;
        q.push({0, start});
        price[start] = 0;
        k++;
        while(!q.empty() && k--)
        {
            int len = q.size();
            while(len--)
            {
                int node = q.front().second;
                int curprice = q.front().first;
                q.pop();
                for(auto neighbor:adj[node])
                {
                    int child = neighbor.second;
                    int weight = neighbor.first;
                    if(price[child] > curprice + weight)
                    {
                        price[child] = curprice + weight;
                        q.push({price[child], child});
                    }   
                }
            }
        }
        // for(auto it:price) cout<<it<<" "; cout<<endl;
        return price[end];
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0;i<flights.size();i++)
        {
            int a = flights[i][0];
            int b = flights[i][1];
            int c = flights[i][2];
            adj[a].push_back({c, b});
        }
        int ans = dijkstra(src, n, k, dst, adj);
        if(ans==1e9) return -1;
        return ans;
    }
};
