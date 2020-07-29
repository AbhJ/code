#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e5+10;
const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
ll f(set<int>a,set<int>b,set<int>c){
  ll x=2e18;
  for(auto i:a){
    auto J=b.lower_bound(i),K=c.upper_bound(i);
    if(J==b.end() or K==c.begin())continue;
    K--;
    ll j=*J,k=*K;
    x=min(x,(j-i)*(j-i)+(k-j)*(k-j)+(k-i)*(k-i));
  }
  return x;
}
void solve(){
  int R,G,B;cin>>R>>G>>B;
  set<int>r,g,b;
  for (int i = 0; i < R; ++i)
  {
    int x;cin>>x;r.insert(x);
  }
  for (int i = 0; i < G; ++i)
  {
    int x;cin>>x;g.insert(x);
  }
  for (int i = 0; i < B; ++i)
  {
    int x;cin>>x;b.insert(x);
  }
  cout<<min(f(r,g,b),min(f(r,b,g),min(f(g,b,r),min(f(g,r,b),min(f(b,g,r),f(b,r,g))))));
}
int main()
{
    ibs;cti;
    int t;cin>>t;
    while(t--){
      solve();
      cout<<"\n";
    }
    return 0;
}