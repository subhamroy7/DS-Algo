class Solution
{
    public:
	typedef pair<int,pair<int,int>> P;
	const vector<int>dx={0,1,-1,0};
	const vector<int>dy={1,0,0,-1};
	 vector<vector<int>> dijkstraOnGrid(vector<vector<int>> &grid)
    {
       int n=grid.size();
        vector<vector<int>>dist(n, vector<int>(n, INT_MAX));
        dist[0][0]=grid[0][0];
       priority_queue<P,vector<P>,greater<P>>q; //{weight,{i,j}}
       q.push({grid[0][0], {0, 0}});
       while(!q.empty()){
           auto it=q.top();
           q.pop();
           int cost=it.first;
           int row=it.second.first;
           int col=it.second.second;
           for(int i=0; i<4; i++){
               int nrow=row+dx[i];
               int ncol=col+dy[i];
               if(ncol>=0 && ncol<n && nrow>=0 && nrow<n && dist[nrow][ncol]>cost+grid[nrow][ncol]){
                   dist[nrow][ncol]=cost+grid[nrow][ncol];
                   q.push({dist[nrow][ncol], {nrow, ncol}});
               }
           }
       }
       return dist; 
    }
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n= grid.size();
        vector<vector<int>>temp= dijkstraOnGrid(grid);
        return temp[n-1][n-1];
    }
};