int Solution::solve(int A, vector<vector<int> > &B) {
    
    int m = B.size();
    if(m==1) return 1;
    vector<vector<int>> adj(A+1);
    
    for(int i=0;i<m;i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
    }
    queue<int> q;
    vector<bool> visited(A+1);
    q.push(1);
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
    }
    if(visited[A]) return 1;
    else return 0;
}

