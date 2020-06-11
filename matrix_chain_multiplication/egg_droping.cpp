#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];


int solve(int floor,int egg)
{
    
    if(floor==1 || floor==0)
    {
        return floor;
    }
    if(egg==1)
    {
        return floor;
    }
    if(dp[egg][floor]!=-1)
    {
        return dp[egg][floor];
    }
    int min_ans = INT_MAX;
    
    for(int k = 1;k<=floor;k++)
    {
        int temp = 1+max(solve(k-1,egg-1),solve(floor-k,egg));
        if(temp<min_ans)
        {
            min_ans = temp;
        }
    }
    return dp[egg][floor] = min_ans;
}

int main()
{
    int t;
    cout<<"enter the number of testcases\n";
    cin>>t;
    while(t--)
    {
        int floor,egg;
        cout<<"enter the number of floors\n";
        cin>>floor;
        cout<<"enter the number of eggs\n";
        cin>>egg;
        memset(dp,-1,sizeof(dp));
        int ans = solve(floor,egg);
        cout<<ans<<"\n";
    }
    return 0;
}
