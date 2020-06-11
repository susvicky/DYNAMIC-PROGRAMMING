#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];

int LCS_substring(string x,string y,int n,int m)
{
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            if(x[i-1]==y[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    int mx = 0;
     for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
           if(dp[i][j]>mx)
           {
               mx = dp[i][j];
           }
        }
    }
    return mx;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string x,y;
    int n,m;
    cin>>n>>m;
    cin>>x;
   
    cin>>y;
    
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0||j==0)
            {
                dp[i][j] = 0;
            }
        }
    }
    
    int ans = LCS_substring(x,y,n,m);
    /*for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    
    cout<<ans<<"\n";
    }
    return 0;
}

