#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];





void LCS(string x,string y,int n,int m)
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
}

void print_LCS(string x,string y,int n,int m)
{
    int i = n,j = m;
    stack<char>s;
    while(i>0 && j>0)
    {
        if(x[i-1]==y[j-1])
        {
            s.push(x[i-1]);
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])\
            {
                i--;
            }
            else{
                j--;
            }
        }
    }
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string x,y;
        cin>>x>>y;
        for(int i=0;i<=x.size();i++)
        {
            for(int j = 0;j<=y.size();j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j] = 0;
                }
            }
        }
        
        LCS(x,y,x.size(),y.size());
        print_LCS(x,y,x.size(),y.size());
    }
    return 0;
}
