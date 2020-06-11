/*
 https://practice.geeksforgeeks.org/problems/edit-distance/0
 */

#include <bits/stdc++.h>
using namespace std;

int dp[101][101];

int solve(string str1,string str2,int n,int m)
{
    if(n==0)
    {
        return m;
    }
    if(m==0)
    {
        return n;
    }
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    
    if(str1[n-1]==str2[m-1])
    {
        return dp[n][m] = solve(str1,str2,n-1,m-1);
    }
    else
    {
        int add = 1+solve(str1,str2,n,m-1);
        int rem = 1+solve(str1,str2,n-1,m);
        int cost = 0;
        if(str1[n-1]!=str2[m-1])
        {
            cost = 1;
        }
        int replace = cost+solve(str1,str2,n-1,m-1);
        return dp[n][m] =min(min(add,rem),replace);
    }
    return dp[n][m];
}




int main() {
    //code
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        string str1,str2;
        cin>>str1>>str2;
        memset(dp,-1,sizeof(dp));
        int ans = solve(str1,str2,n,m);
        cout<<ans<<"\n";
    }
    return 0;
}
