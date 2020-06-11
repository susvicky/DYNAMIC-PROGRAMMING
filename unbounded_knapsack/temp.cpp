
#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];
int coin_change(vector<int>coins,int size,int sum)
{
    for(int i = 2;i<=n;i++)
    {
        for(int j = 1;j<=sum;j++)
        {
            if(coins[i-1]<=j)
            {
                 dp[i][j] = min((1+dp[i][j-coins[i-1]]),dp[i-1][j]);
               
            }
            else
            {
                 dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][sum];
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
                    dp[i][j] = 1000;
                }
                else if(i==0)
                {
                    dp[i][j] = 1000;
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
                dp[1][j] = 1000;
            }
        }
        
        
        int ans = coin_change(coins,n,sum);
        cout<<ans<<"\n";
    }
    return 0;
}
