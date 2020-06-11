#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001][2];

int solve(string s,int start,int end,int is_true)
{
   if(start>end)
       return false;
   if(start==end)
   {
       if(s[start]=='T' && is_true==true)
       {
           return true;
       }
       if(s[start]=='F' && is_true==false)
       {
           return false;
       }
       else
       {
           return false;
       }
   }
    
    int ans = 0;
    
    
    for(int k = start+1;k<end;k+2)
    {
        int l_true,l_false,r_true,r_false;
        
        if(dp[start][k-1][true]!=-1)
        {
            l_true = dp[start][k-1][true];
        }
        else
        {
            l_true = solve(s,start,k-1,true);
        }
        if(dp[start][k-1][false]!=-1)
        {
            l_false = dp[start][k-1][false];
        }
        else
        {
            l_false = solve(s,start,k-1,false);
        }
        if(dp[k+1][end][true]!=-1)
        {
            r_true = dp[k+1][end][true];
        }
        else
        {
            r_true = solve(s,k+1,end,true);
        }
        if(dp[k+1][end][false]!=-1)
        {
            r_false = dp[k+1][end][false];
        }
        else
        {
            r_false = solve(s,k+1,end,false);
        }
        
        
        if(s[k]=='&')
        {
            if(is_true==true)
                ans+= l_true * r_true;
            else
                ans+= l_true*r_false+l_false*r_true+l_false*r_false;
        }
        else if(s[k]=='|')
        {
            if(is_true==true)
            {
                ans+= l_true*r_true+l_false*r_true+l_true*r_false;
            }
        }
        else if(s[k]=='^')
        {
            if(is_true==true)
            {
                ans+= l_true*r_false+l_false*r_true;
            }
            else
            {
                ans+= l_true*r_true+l_false*r_false;
            }
        }
        
    }
    dp[start][end][is_true] = ans;
    return dp[start][end][is_true];
    
}



int main()
{
    int t;
    cout<<"enter the numbner of testcases\n";
    cin>>t;
    while(t--)
    {
        string s;
        int n;
        cout<<"enter the expression\n";
        cin>>s;
        n = s.size();
        int start = 0,end = n-1;
        for(int i=0;i<=n;i++)
        {
            for(int j = 0;j<=n;j++)
            {
                for(int k = 0;k<=1;k++)
                {
                    dp[i][j][k] = -1;
                }
            }
        }
        int ans = solve(s,start,end,true);
        cout<<ans<<"\n";
    }
    return 0;
}

