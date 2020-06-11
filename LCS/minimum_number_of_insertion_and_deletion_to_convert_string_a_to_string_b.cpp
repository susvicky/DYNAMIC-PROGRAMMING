#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];




int LCS(string a,string b,int n,int m)
{
    if(n==0||m==0)
        return 0;
    
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    
    if(a[n-1]==b[m-1])
    {
        return dp[n][m] = 1+LCS(a,b,n-1,m-1);
    }
    else{
        return dp[n][m] = max(LCS(a,b,n-1,m),LCS(a,b,n,m-1));
    }
    return dp[n][m];
}

int main()
{
    string a,b;
    cout<<"enter two strings\n";
    cin>>a>>b;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<=a.size();i++)
    {
        for(int j=0;j<=b.size();j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j] = 0;
            }
        }
    }
    int common = LCS(a,b,a.size(),b.size());
    
    cout<<"minimum number of deletions = "<<a.size()-common<<"\n";
    cout<<"minimum number of insertions = "<<b.size()-common<<"\n";
    return 0;
}
