#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
#define N 100000 
#define M 1000000007
int main()
{   
    ibs;cti;
    	int n,m,i;cin>>n;
        if(n==1){cout<<"4\n";return 0;}
        for (i = 1; i < sqrt(n)+1; ++i)
        {
           if(n%i==0)m=i; 
        }
        n/=m;
        // cout<<n<<"\n"<<m;
        cout<<2*m+2*n<<"\n";
    return 0;
}