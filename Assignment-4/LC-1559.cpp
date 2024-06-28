class Solution {
public:

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool ans=false;

    void dfs(int i, int j, int x, int y,int n, int m,
             vector<vector<char>>& grid, vector<vector<bool>>& visited)
    {
        visited[i][j] = true;
        for(auto it:directions)
        {
            int row = i + it.first;
            int col = j + it.second;
            if(row>=0 && row<n && col>=0 && col<m && grid[i][j]==grid[row][col])
            {
                if(!visited[row][col])
                {
                    dfs(row, col, i, j, n, m, grid, visited);
                }
                else
                {
                    if(row!=x || col!=y)
                    {
                        ans=true;
                    }
                }
            }
        }
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool> (m, false));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j])
                {
                    dfs(i, j, -1, -1, n, m, grid, visited);
                }
            }
        }
        return ans;
    }
};
