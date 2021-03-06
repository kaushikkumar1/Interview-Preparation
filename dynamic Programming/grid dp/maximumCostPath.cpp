#include<bits/stdc++.h>
using namespace std;

int dp[201][201];

//  RECURSIVE

  int recursive(vector<vector<int>> grid,int x,int y){
        if(x<0 || y<0 )
            return INT_MIN;
        
        if(x==0 && y==0)
            return grid[0][0];
            
        int up=recursive(grid,x-1,y);
        int left=recursive(grid,x,y-1);
        return grid[x][y]+max(up,left);
            
    }


//  TOP DOWN
        int maxPathTopDown(vector<vector<int>> grid,int x,int y){
        if(x<0 || y<0 )
            return INT_MIN;
        
        if(x==0 && y==0)
            return grid[0][0];
        
        if(dp[x][y]!=-1)
            return dp[x][y];
            
        int up=maxPathTopDown(grid,x-1,y);
        int left=maxPathTopDown(grid,x,y-1);
        dp[x][y]=grid[x][y]+max(up,left);
            
        return dp[x][y];
    }

    
//   BOTTOM UP
   int maxPathSumBottomUP(vector<vector<int>> grid,int m,int n) {

        for (int i = 1; i < n; i ++) {
            grid[0][i] = grid[0][i] + grid[0][i - 1];
        }

        for (int j = 1; j < m; j ++) {
            grid[j][0] = grid[j][0] + grid[j - 1][0];
        }

        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                grid[i][j] = grid[i][j] + max(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        return grid[m - 1][n - 1];
    }

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> v(n);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            dp[i][j]=-1;
            int x;
            cin>>x;
            v[i].push_back(x);
        }
    }

    cout<<recursive(v,n-1,m-1)<<"\n";
    cout<<maxPathSumBottomUP(v,n,m)<<"\n";
    cout<<maxPathTopDown(v,n-1,m-1)<<"\n";

}

