#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
#define N 100000
int printDivisors(int n) 
{ 
    // Note that this loop runs till square root 
    int count=0;
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            // If divisors are equal, print only one 
            if (n/i == i) 
                count++; 
  
            else // Otherwise print both 
                count+=2;
        } 
    }
    return count; 
} 
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--){
        int a,b,a1,b1;cin>>a>>b;
        a1=min(a,b);b1=max(a,b);
        a=a1;b=b1;
        if(a==b){cout<<-1<<"\n";continue;}
        int num=0;
        cout<<printDivisors(b-a)<<"\n";
    }
    return 0;
}