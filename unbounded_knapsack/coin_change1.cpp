/*
 given an array of coins with unlimited supply  calculate the total number of ways to obtain a given sum
 */

#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int coin_change(vector<int>coins,int size,int sum)
{
    if(sum==0)
    {
        return 1;
    }
    if(size==0 && sum!=0)
    {
        return 0;
    }
    if(dp[size][sum]!=-1)
    {
        return dp[size][sum];
    }
    
    if(coins[size-1]>sum)
    {
        return dp[size][sum] = (coin_change(coins,size-1,sum));
    }
    else
    {
        return dp[size][sum] = (coin_change(coins,size,sum-coins[size-1])+coin_change(coins,size-1,sum));
    }
    return dp[size][sum];
 
}





int main()
{
    int n,x,sum;
    cout<<"enter the size of the array\n";
    cin>>n;
    vector<int>coins;
    cout<<"enter the value of coins\n";
    for(int i=0;i<n;i++)
    {
        cin>>x;
        coins.push_back(x);
    }
    cout<<"enter the sum needed\n";
    cin>>sum;
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
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
    int ans = coin_change(coins,n,sum);
    cout<<ans;
    
    return 0;
}
