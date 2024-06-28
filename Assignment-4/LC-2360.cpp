class Solution {
public:
    int dfs(int v, int cnt, vector<int>& edges, vector<int>& visited, vector<int>& overallvisited)
    {
        // for(auto it:visited) cout<<it<<" "; 
        // cout<<"   ";
        // for(auto it:overallvisited) cout<<it<<" ";
        // cout<<endl;
        if(overallvisited[v]) return -1;
        
        if(edges[v]==-1)
        {
            overallvisited[v] = 1;
            return -1;
        }
        if(visited[v])
        {
            return cnt - visited[v] + 1;
        }
        visited[v] = cnt + 1;
        int ans = dfs(edges[v], cnt+1, edges, visited, overallvisited);
        visited[v] = 0;
        overallvisited[v] = 1;
        return ans;
    }

    int longestCycle(vector<int>& edges) {

        int n = edges.size();
        vector<int> overallvisited(n, 0);
        vector<int> visited(n, 0);

        int ans =-1;

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                int val = dfs(i, 0, edges, visited, overallvisited);
                if(val) ans = max(ans, val);
            }
        }
        return ans;
    }
};
