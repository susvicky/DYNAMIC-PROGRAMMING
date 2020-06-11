#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];

int LCS(string x,string y,int n,int m)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(x[i-1]==y[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string x,y;
    int n,m;
    cout<<"enter the string\n";
    cin>>x;
    y = x;
    reverse(y.begin(),y.end());
    n = x.size();
    m = n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<=n;i++)
    {
        for(int j = 0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j] = 0;
            }
        }
    }
    
    cout<<"string x = "<<x<<"\n";
    cout<<"string y = "<<y<<"\n";
    int ans = LCS(x,y,n,m);
    for(int i=0;i<=n;i++)
    {
        for(int j = 0;j<=m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<ans;
    return 0;
}

