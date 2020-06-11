#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int subset_sum(vector<int>num,int sum,int size)
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
    
    if(num[size-1]>sum)
    {
        return dp[size][sum] = subset_sum(num,sum,size-1);
    }
    else
    {
        return dp[size][sum] = (subset_sum(num,sum-num[size-1],size-1)+subset_sum(num,sum,size-1));
    }
    
    return dp[size][sum];
}

int main()
{
    int n,x,diff,sum = 0;
    cout<<"enter the size of array\n";
    cin>>n;
    vector<int>num;
    cout<<"enter the elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>x;
        sum+=x;
        num.push_back(x);
    }
    cout<<"enter the difference\n";
    cin>>diff;
    
    /*
     
     subset1 - subset2 = diff................1
     subset1 + subset2 = sum(num).............2
     
     1+2=> 2*subset1 = diff + sum(num)
     subset1 = (diff+sum(num))/2
     
     */
    
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
    
    int subset_one = (diff+sum)/2;
    int ans = subset_sum(num,subset_one,n);
    cout<<ans;
    
return 0;
    
}
