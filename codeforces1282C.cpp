#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e6+3;
const ll M = 1000000007; // modulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
void solve(){
  ll n,T,a,b;cin>>n>>T>>a>>b;std::vector<pair<ll,bool> > v(n);ll A=0,B=0;
  for (int i = 0; i < n; ++i){cin>>v[i].S;if(v[i].S)B++;else A++;}
  for (int i = 0; i < n; ++i)cin>>v[i].F;
  sort(v.begin(), v.end());ll t=0,c=0,s=0;
  for (int i = 0; i < n; ++i)
  {
    ll t=v[i].F,x,y;if(s<t)x=min(A,(t-1-s)/a),y=min(B,(t-1-s-x*a)/b),c=max(c,x+y+i);
    if(!v[i].S)s+=a,A--;else s+=b,B--;
  }
  if(s<=T)c=max(c,n);
  cout<<c;
}
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--)
    solve(),cout<<"\n";
    return 0;
}