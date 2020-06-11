//https://practice.geeksforgeeks.org/problems/nth-catalan-number/0
#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;
using namespace std;
cpp_int catalan(cpp_int);
cpp_int binomial(cpp_int,cpp_int);
int main() {
    //code
    int t;
    cin>>t;
    while(t--)
    {
        cpp_int n;
        cin>>n;
        cout<<catalan(n)<<"\n";
    }
    return 0;
}
cpp_int catalan(cpp_int n)
{
    cpp_int b=binomial(2*n,n);
    return b/(n+1);
}
cpp_int binomial(cpp_int n,cpp_int k)
{
    cpp_int ans=1;
    if(k>n-k)
    {
        k=n-k;
    }
    for(long int i=0;i<k;i++)
    {
        ans= ans*(n-i);
        ans=ans/(i+1);
    }
    return(ans);
}
