#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int ugly(int);
int main()
{
    int n;
    cout<<"enter the value of n\n";
    cin>>n;
    cout<<ugly(n)<<"\n";
    return 0;
}
int ugly(int n)
{
    int dp[n];
    dp[0]=1;
    int i2,i3,i5;
    
    int next_ugly_number;
    next_ugly_number=1;
    int next_multiple_of_2=2;
    int next_multiple_of_3=3;
    int next_multiple_of_5=5;
    i2=i3=i5=0;
    for(int i=1;i<n;i++)
    {
        next_ugly_number=min(min(next_multiple_of_2,next_multiple_of_3),next_multiple_of_5);
        
        dp[i]=next_ugly_number;
        cout<<dp[i]<<"\n";
        if(next_ugly_number==next_multiple_of_2)
        {
            i2+=1;
            next_multiple_of_2=dp[i2]*2;
        }
        if(next_ugly_number==next_multiple_of_3)
        {
            i3+=1;
            next_multiple_of_3=dp[i3]*3;
        }
        if(next_ugly_number==next_multiple_of_5)
        {
            i5+=1;
            next_multiple_of_5=dp[i5]*5;
        }
    }
    return next_ugly_number;
}
