#include<bits/stdc++.h>
using namespace std;
int pos1,pos2;
void kadane(int *arr,int n)
{
    
    int max_till_now=0,max=INT_MIN;
    int s=0;
    for(int i=0;i<n;i++)
    {
        max_till_now+=arr[i];
        if(max_till_now>max)
        {
            max=max_till_now;
            pos1=s;
            pos2=i;
        }
        if(max_till_now<0)
        {
            max_till_now=0;
            s=i+1;
        }
        
    }
    cout<<"maximum = "<<max<<"\n";
    cout<<"start = "<<pos1<<" end = "<<pos2<<"\n";

}
int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    kadane(A,n);
    
}
