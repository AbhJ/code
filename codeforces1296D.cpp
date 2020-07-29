#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e5+3;
const long M = 1000000007; // modulo
int main()
{   
    ibs;cti;
      ll i,n,a,b,k;cin>>n>>a>>b>>k;std::vector<ll> v(n);
      for (int i = 0; i < n; ++i){
        cin>>v[i];v[i]=(v[i]-1)%(a+b)/a;
      }
      sort(v.begin(), v.end());
      for (i = 0; i < n; ++i)
      {
        k-=v[i];if(k<0)break;
      }
      cout<<i<<"\n";
    // cout<<day_of_week(2020,3,1);
    return 0;
}