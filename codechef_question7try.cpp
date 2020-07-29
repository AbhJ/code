#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e5+3;
const long M = 1000000007; // modulo
ll modInverse(ll a, ll m) 
{ 
    a = a%m; 
    for (ll x=1; x<m; x++) 
       if ((a*x) % m == 1) 
          return x;
    return 0;
}
int main()
{   
    ibs;cti;int t;cin>>t;
    while(t--){
      ll n,num=0,den=0;cin>>n;string s;cin>>s;
      ll no=0,nc=0;
      for (int l = 0; l < n; ++l)
      {
        for (int r = l; r < n; ++r)
        {
          string x=s;no=0,nc=0;
          for (int i = l; i < r+1; ++i)
          {
            den++;
            // if(x[i]==')' and nc==no){no++,x[i]='(',num++;continue;}
            // if(x[i]==')')nc++;else no++;
            if(x[i]==')')nc++;else no++;
            if(x[i]==')' and nc>no){x[i]='(',nc--,no++,num++;continue;}
          }
        }
      }
      cout<<num<<" "<<den<<"\n";
      cout<<(num*modInverse(den,M))%M;
    }
    // cout<<day_of_week(2020,3,1);
    return 0;
}