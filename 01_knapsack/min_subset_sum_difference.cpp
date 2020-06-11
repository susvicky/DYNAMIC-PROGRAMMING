#include <bits/stdc++.h>
using namespace std;
int dp[10001][10001];

void subset_sum(vector<int>num,int sum,int size)
{
   
    for(int i=1;i<=size;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(num[i-1]>j)
            {
               dp[i][j] = dp[i-1][j];
            }
            else
            {
               dp[i][j] = dp[i-1][j-num[i-1]] || dp[i-1][j];
            }

        }
    }
}

int main() {
    //code
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        int range = 0;
        vector<int>num;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            range+=x;
            num.push_back(x);
        }
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=range;j++)
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
                
            }
        }
       subset_sum(num,range,n);
        
        /*for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=range;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }*/
        
       vector<int>values;
        for(int i=0;i<=range/2;i++)
        {
            if(dp[n][i]==1)
            values.push_back(i);
        }
        cout<<"values\n";
        for(int i=0;i<values.size();i++)
        {
            cout<<values[i]<<" ";
        }
        cout<<"\n";
        int min_s = INT_MAX;
        for(int i=0;i<values.size();i++)
        {
            min_s = min(min_s,range-2*values[i]);
        }
        cout<<"ans = "<<min_s<<"\n";
    }
    return 0;
}
