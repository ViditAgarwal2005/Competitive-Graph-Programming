class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    queue<int> q;
	    vector<int> visited(V+1);
	    vector<int> d(V+1);
	   // int level=0;
	    q.push(0);
	    visited[0]=1;
	    while(!q.empty())
	    {
	       // level++;
	        int elem=q.front();
	        q.pop();
	        for(auto i:adj[elem])
	        {
	            if(!visited[i])
	            {
	                visited[i]=1;
	                q.push(i);
	                d[i] = d[elem]+1;
	            }
	        }
	    }
	    if(d[X]==0 && X) return
	    return d[X];
	    
	}
};
