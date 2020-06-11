#include<bits/stdc++.h>
using namespace std;
int LIS(vector<int>,int);
int main()
{
    int t;
    cin>>t;
    
      while(t--)
      { 
          int n;
          cin>>n;
          map<int,int>m;
          vector<int>north;
          vector<int>south;
          int x,y;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            north.push_back(x);
        }
        for(int i=0;i<n;i++)
        {
            cin>>y;
            south.push_back(y);
        }
        for(int i=0;i<n;i++)
        {
            m.insert(pair<int,int>(south[i],north[i]));
        }
        vector<int>v;
        map<int,int>:: iterator itr;
        
        for(itr=m.begin();itr!=m.end();itr++)
        {
                
            v.push_back(itr->second);
            
        }
        
       
          cout<<LIS(v,v.size())<<"\n";
      }
     
    return 0;
}

int LIS(vector<int>A,int n)
{
    int *L=(int *)malloc(sizeof(int)*n);
    
    for(int i=0;i<n;i++)
        L[i]=1;
    
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A[i]>A[j] && L[i]<L[j]+1)
            {
                L[i]=L[j]+1;
            }
        }
    }
    
    int max =0;
    
    for(int i=0;i<n;i++)
    {
        if(L[i]>max)
        {
            max=L[i];
        }
    }
    delete []L;
    return max;
    
}