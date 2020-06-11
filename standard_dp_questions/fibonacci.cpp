//using recursion
#include<iostream>
using namespace std;
/*long long int fib(long long int n,long long int *arr)
{
    if(n==0 || n==1)
        return 1;
    if(arr[n]!=0)
        return arr[n];
    long long int output =fib(n-1,arr)+fib(n-2,arr);
    arr[n]=output;
    return arr[n];
}*/
//without recursion
long long int fib1(long long int n)
{
    long long int * arr;
    arr = new long long int[n+1];
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i<=n;i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    }
    long long int output = arr[n];
    delete [] arr;
    return(output);
}
int main()
{
    long long int n;
    cout<<"Enter the number \n";
    cin>>n;
   long long  int *arr;
    arr = new long long int [n+1];
    for(int i=0;i<=n;i++)
        arr[i]=0;
    //cout<<"using recursion:"<<fib(n,arr)<<"\n";
    delete [] arr;
    cout<<"The "<<n<<"th fibonacci number is :"<<fib1(n)<<"\n";
    return 0;
}
