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
ll B[N],A[N];
bool cmp(pair<ll,ll> a,pair<ll,ll> b){
  return a.S-a.F<b.S-b.F;
}
void solve(){
  int n;cin>>n;
  std::vector<pair<ll,ll>> v(n);
  for (int i = 0; i < n; ++i)
  {
    cin>>v[i].F>>v[i].S;
  }
  sort(v.begin(), v.end(),cmp);
  ll x=0;
  for (int i = 0; i < n; ++i)
  {
    x+=v[i].F*i+v[i].S*(n-i-1);
  }
  cout<<x;
}
int main()
{
    ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      cout<<"\n";
    // }
    return 0;
}