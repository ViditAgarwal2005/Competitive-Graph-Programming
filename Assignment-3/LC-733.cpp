class Solution {
public:

    vector<pair<int, int>> direc = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void bfs(vector<vector<int>>& image, int new_color, int old_color, 
            int r, int c, vector<vector<bool>>& visited)
    {
        int n = image.size();
        int m = image[0].size();
        
        visited[r][c] = true;
        image[r][c] = new_color;
        queue<pair<int, int> > q;
        q.push({r, c});
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(auto it:direc)
            {
                int i = row + it.first;
                int j = col + it.second;

                if(i>=0 && i<n && j>=0 && j<m)
                {
                    if(image[i][j]==old_color && !visited[i][j])
                    {
                        visited[i][j] = true;
                        q.push({i, j});
                        image[i][j] = new_color;
                    }
                }
            }
        }

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        int old_color = image[sr][sc];
        int new_color = color;

        bfs(image, new_color, old_color, sr, sc, visited);

        return image;
    }
};
