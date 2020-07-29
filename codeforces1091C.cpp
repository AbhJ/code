#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e7+3;
const int M = 1000000007; // modulo
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
void solve(){
      ll n;cin>>n;
      set<ll>q;
      for (int i=1; i<=sqrt(n); i++) 
      { 
          if (n%i == 0) 
          { 
            q.insert(n*(i-1)/2+i);
            q.insert(n*(n/i-1)/2+n/i);
          }
      }
      for(auto x:q)
        cout<<x<<" ";
}
int main()
{   
    ibs;cti;
    solve();
    cout<<"\n";
    return 0;
}