class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        int m = edges.size();
        cout<<m<<endl;

        for(int i=0;i<m;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        queue<int> q;
        vector<bool> visited(n, false);
        visited[source]=true;
        q.push(source);
        
        while(!q.empty())
        {
            int elem = q.front();
            q.pop();
            for(auto i:adj[elem])
            {
                if(!visited[i])
                {
                    visited[i]=true;
                    q.push(i);
                }
            }
            if(elem==destination) return true;
        }
        return false;
    }
};
