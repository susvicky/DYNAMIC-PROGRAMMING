#include<iostream>
using namespace std;
int dp[3][3];
int mincost(int r,int c,int cost[3][3])
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(i==0 && j==0)
            {
                dp[i][j]=cost[0][0];
            }
            else if(i==0)
            {
                dp[i][j]=dp[0][j-1]+cost[i][j];
            }
            else if(j==0)
            {
                dp[i][j]=dp[i-1][j]+cost[i][j];
            }
            else
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+cost[i][j];
        }
    }
    return dp[r-1][c-1];
}
int main()
{
    int cost[3][3]={
        {1,2,1},
        {2,1,2},
        {2,1,1},
                   };
    cout<<mincost(3,3,cost);
    return 0;
    
}
