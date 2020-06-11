/*https://leetcode.com/problems/partition-equal-subset-sum/submissions/ */

#include<bits/stdc++.h>
using namespace std;
    

    
    bool equal_sum(vector<int>v,int sum,int n)
    {
        if(sum%2!=0)
        {
             return false;
        }
   
         int dp[n+1][sum/2+1];
      
        
        for (int i = 0; i <= n; i++)
            dp[i][0] = true;
   
     
        for (int i = 1; i <= sum/2; i++)
            dp[0][i] = false;
      
        for(int i=1;i<=n;i++)
        {
            for(int j = 1;j<=sum/2;j++)
            {
                if(v[i-1]<=j)
                {
                    dp[i][j] = dp[i-1][j-v[i-1]] || dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    
    return dp[n][sum/2];
}
    
    
    
    
    
    bool canPartition(vector<int>& nums) {
        
        int sum = 0;
        for(int i = 0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        
        bool ans = equal_sum(nums,sum,nums.size());
        return ans;
    }


int main()
{
    int n,sum=0,x;
    vector<int>v;
    cout<<"enter the size of array\n";
    cin>>n;
    cout<<"enter the elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
        sum+=x;
    }
    if(canPartition(v))
    {
        cout<<"YES"<<"\n";
    }
    else
    {
        cout<<"NO"<<"\n";
    }
    return 0;
}

