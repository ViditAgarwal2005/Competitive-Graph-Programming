class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        // graph is adjacency list
        int n = adj.size();

        vector<int> color(n, 0);
        // 1 is 1st color, 2 is 2nd color, 0 is not colored yet
        vector<int> visited(n, 0);
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                q.push(i);
            }
            while(!q.empty())
            {
                int elem = q.front();
                q.pop();
                for(auto it:adj[elem])
                {
                    if(!visited[it])
                    {
                        if(color[elem]==1) color[it]=2;
                        else color[it]=1;
                        visited[it] = 1;
                        q.push(it);
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(auto j:adj[i])
            {
                if(color[i]==color[j])
                {
                    return 0;
                }
            }
        }
        return 1;
    }
};
