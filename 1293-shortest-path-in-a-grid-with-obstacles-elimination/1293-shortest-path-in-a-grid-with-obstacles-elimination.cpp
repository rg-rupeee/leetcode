class Solution {
public: 
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<bool>>> v(n,vector<vector<bool>>(m,vector<bool>(k+1,false)));
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},k});
        int steps=0;
        v[0][0][k]==true;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty())
        {
            int size=q.size();
            while(size-->0)
            {
                auto curr=q.front();
                q.pop();
                if(curr.first.first==n-1 && curr.first.second==m-1)
                    return steps;
                for(int i=0;i<4;i++)
                {
                    int rw=curr.first.first+delrow[i];
                    int cl=curr.first.second+delcol[i];
                    int obs=curr.second;
                    
                    if(rw>=0 && rw<n && cl>=0 && cl<m)
                    {
                        if(grid[rw][cl]==0 && !v[rw][cl][obs])
                        {
                            v[rw][cl][obs]=true;
                            q.push({{rw,cl},obs});
                        }
                        else if(grid[rw][cl]==1 && obs>0 && !v[rw][cl][obs-1])
                        {
                            v[rw][cl][obs-1]=true;
                            q.push({{rw,cl},obs-1});
                        }
                    }
                }
            }
            
            steps++;
        }
        return -1;
    }
};