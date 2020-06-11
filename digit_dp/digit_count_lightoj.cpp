
/*
 1122 - Digit Count
 lightoj.com/volume_showproblem.php?problem=1122
 */
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int dp[12][12];

ll go(vector<ll>s,ll n,ll pos = 0,ll prev = 0)
{
    ll res = 0;
    if(dp[pos][prev]!=-1)
    {
        return dp[pos][prev];
    }
    if(pos==n)
    {
        return 1;
    }
    
    for(ll j = 0;j<s.size();j++)
    {
        if(prev==0 || (abs(s[j]-prev)<=2))
        {
            res+=go(s,n,pos+1,s[j]);
        }
    }
    return dp[pos][prev] = res;
}




int main()
{
    ll t;
    cin>>t;
    for(int test_case = 1;test_case<=t;test_case++)
    {
        ll n,m;
        cin>>m>>n;
        memset(dp,-1,sizeof(dp));
        vector<ll>s;
        ll x;
        for(ll i=0;i<m;i++)
        {
            cin>>x;
            s.push_back(x);
        }
        
        ll ans = go(s,n);
        cout<<"CASE "<<test_case<<" : "<<ans<<"\n";
    }
    return 0;
}
