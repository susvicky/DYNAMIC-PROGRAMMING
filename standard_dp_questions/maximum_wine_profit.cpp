//https://www.hackerearth.com/practice/notes/dynamic-programming-i-1/


#include<bits/stdc++.h>
using namespace std;
int price[] = { 2, 4, 6, 2, 5 }; 
int n=sizeof(price) / sizeof(price[0]);
int dp[1000][1000] = {0};
int maxProfit(int start,int end)
{
    
    if(start>end)
    return 0;
    
    if(dp[start][end]!=0)
    return(dp[start][end]);
    int sold_wines=n-(end-start)-1;
    int year= sold_wines+1;
    int ifstart=price[start]*year+maxProfit(start+1,end);
    int ifend=price[end]*year+maxProfit(start,end-1);
    return dp[start][end]=max(ifstart,ifend);
}
int main()
{
  
    int ans = maxProfit(0,4); 
  
    cout << ans << endl; 
  
    return 0; 
}
