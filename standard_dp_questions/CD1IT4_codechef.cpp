/*A robot is designed to move on a rectangular grid of M rows and N columns. The robot is initially positioned at (1, 1), i.e., the top-left cell. The robot has to reach the (M, N) grid cell. In a single step, robot can move only to the cells to its immediate east and south directions. That means if the robot is currently at (i, j), it can move to either (i + 1, j) or (i, j + 1) cell, provided the robot does not leave the grid.
 
 Now somebody has placed several obstacles in random positions on the grid, through which the robot cannot pass. Given the positions of the blocked cells, your task is to count the number of paths that the robot can take to move from (1, 1) to (M, N).
 
 Since the answer can get very large, output the answer modulo 1000000007.
 
 Input
 The first line contains 3 integers M, N and P denoting the number of rows, number of columns and number of blocked cells respectively.
 In the next P lines, each line has exactly 2 integers i and j denoting that the cell (i, j) is blocked.
 
 Output
 Output should contain a single integer, the number of paths modulo 1000000007.
 
 Constraints
 1 <= M, N <= 103
 0 <= P <= M * N
 1 <= i <= M
 1 <= j <= N
 Example
 Input
 4 3 2
 3 3
 3 1
 
 Output
 2
 */
#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
#define MOD 1000000007
int num_of_ways(int m,int n)
{
    if(dp[0][0]==-1)
    return 0;
    
    for(int i=0;i<m;i++)
    {
        if(dp[i][0]==-1)
            break;
        
        dp[i][0]=1;
        
    }
    for(int i=0;i<n;i++)
    {
        if(dp[0][i]==-1)
            break;
        
        dp[0][i]=1;
        
    }
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(dp[i][j]==-1)
            {
                continue;
            }
            dp[i][j]=0;
            if(dp[i][j-1]!=-1)
            {
                dp[i][j]=dp[i][j-1]%MOD;
            }
            if(dp[i-1][j]!=-1)
            {
                dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
            }
        }
    }
    if(dp[m-1][n-1]==-1)
    return 0;
    
    return dp[m-1][n-1];
}
int main() {
	// your code goes here
	memset(dp,0,sizeof dp);
	int m,n,p;
	cin>>m>>n>>p;

	for(int loop=0;loop<p;loop++)
	{
	    int i,j;
	    cin>>i>>j;
	    dp[i-1][j-1]=-1;
	}
	
	cout<<num_of_ways(m,n);
	return 0;
}
