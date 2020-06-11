//https://www.geeksforgeeks.org/bell-numbers-number-of-ways-to-partition-a-set/
//Use bell triangle concept for dp implementation
#include<bits/stdc++.h>
int bell_number(int);
using namespace std;
int main()
{
    int n;
    cin>>n;
    cout<<bell_number(n);
    return 0;
}
int bell_number(int n)
{
    int dp[n+1][n+1];
    dp[0][0]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j==0)
            {
                dp[i][j]=dp[i-1][i-1];
            }
            else
            {
                dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
            }
        }
    }
    return dp[n-1][n-1];
}
