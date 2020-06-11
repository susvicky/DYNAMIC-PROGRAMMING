/*
  GONE - G-One Numbers
https://www.spoj.com/problems/GONE/
 */
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int dp[10][80][2];

ll prime[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109};

bool check(ll x)
{
    for(auto i:prime)
    {
        if(i==x)
        {
            return true;
        }
    }
    return false;
}

ll g(string num,ll pos = 0, ll sum = 0, ll tight = 1)
{
    if(pos==num.length())
    {
        if(check(sum))
            return 1;
        else
            return 0;
    }
    else if(dp[pos][sum][tight]!=-1)
    {
        return dp[pos][sum][tight];
    }
    else if(tight==1)
    {
        ll res = 0;
        for(ll i=0;i<=num[pos]-'0';i++)
        {
            if(i==num[pos]-'0')
            {
                res+=g(num,pos+1,sum+i,1);
            }
            else
            {
                res+=g(num,pos+1,sum+i,0);
            }
        }
        dp[pos][sum][tight] = res;
        return res;
    }
    else
    {
        ll res = 0;
        for(ll i=0;i<=9;i++)
        {
            res+=g(num,pos+1,sum+i,0);
        }
        dp[pos][sum][tight] = res;
        return res;
    }
    
}





int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll left,right;
        cin>>left>>right;
        left = left-1;
        
        string l = to_string(left);
        string r = to_string(right);
        
        memset(dp,-1,sizeof(dp));
        ll ans1 = g(l);
        memset(dp,-1,sizeof(dp));
        ll ans2 = g(r);
        
        cout<<ans2-ans1<<"\n";
    }
    return 0;
}
