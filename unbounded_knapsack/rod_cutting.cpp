/*
 Given an integer N denoting the Length of a line segment. you need to cut the line segment in such a way that the cut length of a line segment each time is integer either x , y or z. and after performing all cutting operation the total number of cutted segments must be maximum.


 Input
 First line of input contains of an integer 'T' denoting number of test cases. First line of each testcase contains N . Second line of each testcase contains 3 space separated integers x , y and z.

 Output
 For each test case print in a new line an integer corresponding to the answer .


 Constraints
 1<=t<=70
 1<=N,x,y,z<=4000
 */






#include <bits/stdc++.h>
using namespace std;



int rod(int length,int x,int y,int z)
{
  int dp[length+1];
  dp[0] = 0;
  
  for(int i=1;i<=length;i++)
  {
      dp[i] = -1;
      if(i-x>=0)
      {
          dp[i] = max(dp[i],dp[i-x]);
      }
      if(i-y>=0)
      {
          dp[i] = max(dp[i],dp[i-y]);
      }
      if(i-z>=0)
      {
          dp[i] = max(dp[i],dp[i-z]);
      }
      
      if(dp[i]!=-1)
      dp[i]++;
  
  }
  return dp[length];
  
}




int main() {
    //code
    int t;
    cin>>t;
    while(t--)
    {
        int length,x,y,z;
        cin>>length>>x>>y>>z;
        
        
        int max_pieces = rod(length,x,y,z);
        cout<<max_pieces<<"\n";
    }
    return 0;
}
