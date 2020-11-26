#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[101][101];
ll rows,cols;



//Recursion gives tle
ll recursion(ll i, ll j) {
    if(i < 0 || i >= rows || j < 0 || j >= cols)
      return 0;
  
    if(i == rows - 1 && j == cols -1)
      return 1;
  
    return recursion(i, j + 1) + recursion(i + 1, j);
}


//TOP DOWN
long long topDown(int i,int j)
{
  if(i==rows-1 && j==cols-1)
    return 1;
  if(i>=rows || j>=cols)
    return 0;
  if(dp[i][j]!=-1)
    return dp[i][j];
  
  dp[i][j]=(topDown(i+1,j)+topDown(i,j+1));
  return dp[i][j];
} 


//BOTTOM UP
ll numberOfPaths(ll m, ll n) 
{ 
    ll count[m+1][n+1]; 
  
    for (ll i = 0; i < m; i++) { 
        for (ll j = 0; j < n; j++) {
            if(i==0 || j==0)         //if it is first row or colum count[i][j]=1;
              count[i][j]=1;
            else
              count[i][j] = count[i - 1][j] + count[i][j - 1];  
        }
    } 
    return count[m - 1][n - 1]; 
} 


ll countPaths(ll r, ll c)
{
  if(r==0 && c==0) return 0;
  rows=r;cols=c;
  // return uniquePathsHelper(0,0); //bottom up
  // return topDown(0,0);
}



int main()
{
    ll t, n,r,c;
    scanf("%lld", &t);
    while(t--){


        //memset(dp,-1,sizeof dp) //if using top down un comment this line
        scanf("%lld %lld", &r, &c);
        printf("%lld\n", countPaths(r, c));
    }
    return 0;
}