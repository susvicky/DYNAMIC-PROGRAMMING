
#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];

int LCS_substring(string x,string y,int n,int m,int &mx)
{
    if(n==0 || m==0)
        return 0;
    
    if(dp[n][m]!=-1)
        return dp[n][m];
    
    if(x[n-1]==y[m-1])
    {
        dp[n][m] = 1+LCS_substring(x,y,n-1,m-1,mx);
        mx = max(mx,dp[n][m]);
        return dp[n][m];
    }
    else
    {
        dp[n][m] = 0;
        LCS_substring(x,y,n-1,m,mx);
        LCS_substring(x,y,n,m-1,mx);
        mx = max(mx,dp[n][m]);
    }
    
   
}

int main()
{
    string x,y;
    int n,m;
    cout<<"enter string X\n";
    cin>>x;
    n = x.size();
    cout<<"enter string y\n";
    cin>>y;
    m = y.size();
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
    int mx = 0;
    int ans = LCS_substring(x,y,n,m,mx);
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    cout<<mx;
    return 0;
}
