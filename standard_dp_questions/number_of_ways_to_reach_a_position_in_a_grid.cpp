#include<iostream>
using namespace std;
int dp[3][3];
int number_of_ways(int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(i==0 && j==0)
            {
                dp[i][j]=1;
            }
            else if(i==0)
            {
                dp[i][j]=1;
            }
            else if(j==0)
            {
                dp[i][j]=1;
            }
            else
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
                
            }

        }
    }
    return dp[r-1][c-1];
}
int main()
{
    int r=3,c=3;
    cout<<number_of_ways(r,c);
    return 0;
}
