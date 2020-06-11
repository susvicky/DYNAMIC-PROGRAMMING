#include<bits/stdc++.h>
using namespace std;
int dp[10001][10001];
int subset_sum(vector<int>&v,int size,int sum)
{
    if(sum==0)
        return 1;
    if(size==0 && sum!=0)
        return 0;
    
    if(dp[size][sum]!=-1)
    {
        return dp[size][sum];
    }
    
    
    if(v[size-1]>sum)
    {
        return dp[size][sum] = (subset_sum(v,size-1,sum));
    }
    else
    {
        return dp[size][sum] = (subset_sum(v,size-1,sum-v[size-1])+subset_sum(v,size-1,sum));
    }
}


int main()
{
    int n,x,sum;
    vector<int>num;
    cout<<"enter the number of elements\n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        num.push_back(x);
    }
    cout<<"enter the sum\n";
    cin>>sum;
    for(int i = 0;i<=n;i++)
    {
        for(int j = 0;j<=sum;j++)
        {
            dp[i][j] = -1;
        }
    }
    for(int i=0;i<=sum;i++)
    {
        dp[0][i] = 0;
    }
    for(int j = 0;j<=n;j++)
    {
        dp[j][0] = 1;
    }
    int ans = subset_sum(num,n,sum);
    cout<<ans;
    return 0;
}
