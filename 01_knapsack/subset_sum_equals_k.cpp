#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[10001][10001];

ll subset_sum(vector<ll>&v,ll n,ll sum)
{
    
    if(n==0 && sum==0)
    {
        return  1;
    }
    if(sum==0)
    {
        return  1;
    }
    if(n==0 && sum!=0)
    {
        return 0;
    }
    if(dp[n][sum]!=-1)
    {
        return dp[n][sum];
    }
    if(v[n-1]>sum)
    {
        return dp[n][sum] = subset_sum(v,n-1,sum);
    }
    else
    {
        return dp[n][sum] =  (subset_sum(v,n-1,sum-v[n-1])||(subset_sum(v,n-1,sum)));
    }
    
}


int main()
{
    vector<ll>v;
    ll x,sum,n;
    cout<<"enter the size of array\n";
    cin>>n;
    cout<<"enter the elements\n";
    for(ll i = 0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    cout<<"enter the sum\n";
    cin>>sum;
    for(ll i = 0;i<=n;i++)
    {
        for(ll j = 0;j<=sum;j++)
        {
            if(i==0 && j==0)
            {
                dp[i][j] = 1;
            }
            else if(i==0)
            {
                dp[i][j] = 0;
            }
            else if(j==0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = -1;
            }
        }
    }
    ll ans = subset_sum(v,n,sum);
    cout<<ans<<"\n";
    for(ll i = 0;i<=n;i++)
    {
        for(ll j = 0;j<=sum;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
