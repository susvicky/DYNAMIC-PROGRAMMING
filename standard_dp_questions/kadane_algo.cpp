#include<bits/stdc++.h>
using namespace std;
int max_contiguous_sum(int *,int);
int dp_solution(int *,int);
int main()
{
    int n;
    cout<<"enter the size\n";
    cin>>n;
    int A[n];
    cout<<"enter the elements\n";
    for(int i=0;i<n;i++)
        cin>>A[i];
    cout<<"solution using kadane algorithm: "<<max_contiguous_sum(A,n)<<"\n";
    cout<<"solution using dp: "<<dp_solution(A,n)<<"\n";
    return 0;
}
int max_contiguous_sum(int *A,int n)
{
    int max_till_now=INT_MIN,max_end=0;
    
    for(int i=0;i<n;i++)
    {
        max_end+=A[i];
        
        if(max_till_now<max_end)
        {
            max_till_now=max_end;
        }
        if(max_end<0)
        {
            max_end=0;
        }
    }
    return max_till_now;
}
int dp_solution(int *A,int n)
{
    int dp[n];
    for(int i=0;i<n;i++)
    {
        dp[i]=0;
    }
    
    if(A[0]>0)
    {
        dp[0]=A[0];
    }
    else{
        dp[0]=0;
    }
    int max_sum=0;
    for(int i=1;i<n;i++)
    {
        if(A[i]+dp[i-1]>0)
        {
            dp[i]=A[i]+dp[i-1];
        }
        else
            dp[i]=0;
        
    }
    for(int i=0;i<n;i++)
    {
        if(max_sum<dp[i])
        {
            max_sum=dp[i];
        }
    }
    return max_sum;
}












