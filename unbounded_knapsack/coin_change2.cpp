#include<bits/stdc++.h>
using namespace std;

int dp[10001][10001];
int coin_change(vector<int>coins,int size,int sum)
{
    if(sum==0)
    {
        return 0;
    }
    if(size==0 && sum!=0)
    {
        return INT_MAX;
    }
    if(dp[size][sum]!=-1)
    {
        return dp[size][sum];
    }
    if(coins[size-1]>sum)
    {
        return dp[size][sum] = coin_change(coins,size-1,sum);
    }
    else
    {
        return dp[size][sum] = (min(1+coin_change(coins,size,sum-coins[size-1]),coin_change(coins,size-1,sum)));
    }
    return dp[size][sum];
}





int main()
{
    int t;
    cout<<"enter the number of testcases\n";
    cin>>t;
    while(t--)
    {
        int n,x,sum;
        cout<<"enter the size of array\n";
        cin>>n;
        vector<int>coins;
        cout<<"enter the elements of array\n";
        for(int i=0;i<n;i++)
        {
            cin>>x;
            coins.push_back(x);
        }
        cout<<"enter the sum\n";
        cin>>sum;
        
        
        for(int i = 0;i<=n;i++)
        {
            for(int j = 0;j<=sum;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j] = INT_MAX-1;
                }
                else if(i==0)
                {
                    dp[i][j] = INT_MAX-1;
                }
                else if(j==0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = -1;
                }
            }
        }
        
        for(int j = 1;j<=sum;j++)
        {
            if(j%coins[0]==0)
            {
                dp[1][j] = j/coins[0];
            }
            else
            {
                dp[1][j] = INT_MAX-1;
            }
        }
        
        
        int ans = coin_change(coins,n,sum);
        cout<<ans<<"\n";
    }
    return 0;
}
