#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];

bool is_palindrome(string s,int start,int end)
{
    if(start>end)
        return false;
    if(start==end)
        return true;
    while(start<end)
    {
        if(s[start]!=s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}



int solve(string s,int start,int end)
{
    if(start>=end)
    {
        return 0;
    }
    if(is_palindrome(s,start,end))
    {
        return 0;
    }
    if(dp[start][end]!=-1)
    {
        return dp[start][end];
    }
    int min_ans = INT_MAX;
    for(int k = start;k<end;k++)
    {
        int left,right;
        if(dp[start][k]!=-1)
        {
            left = dp[start][k];
        }
        else
        {
            left = solve(s,start,k);
        }
        if(dp[k+1][end]!=-1)
        {
            right = dp[k+1][end];
        }
        else
        {
            right = solve(s,k+1,end);
        }
        
        int temp_ans = 1+left+right;
        min_ans = min(min_ans,temp_ans);
    }
    return dp[start][end] = min_ans;
}



int main()
{
    int t;
    cout<<"enter the numbner of testcases\n";
    cin>>t;
    while(t--)
    {
        string s;
        int n;
        cout<<"enter the string\n";
        cin>>s;
        n = s.size();
        int start = 0,end = n-1;
        memset(dp,-1,sizeof(dp));
        int ans = solve(s,start,end);
        cout<<ans<<"\n";
    }
    return 0;
}
