#include <bits/stdc++.h>
// #include <xeric>QC
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=3e5+10;
const ll M = 998244353 ; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
ll mul(ll a,ll b){
  return ((a%M)*(b%M))%M;
}
ll add(ll a,ll b){
  return ((a%M)+(b%M))%M;
}
ll sub(ll a,ll b){
  return ((a%M)-(b%M)+M)%M;
}
int n;
ll fac[N];
void fact(ll x) {
    fac[0] = 1;
    for (int i = 1; i <= x; ++i) {
       fac[i] = mul(i , fac[i - 1]);
    }
}
ll f(int a[]){
  map<int, int> m;
  for (int i = 0; i < n; ++i)
  {
    m[a[i]]++;
  }
  ll ans=1;
  for (int i = 0; i < n; ++i)
  {
    if(m.count(i))ans=mul(ans,fac[m[i]]);
  }
  return ans;
}
int a[N],b[N];
ll f1(){
  map<pair<int,int>,int>m;
  vector<pair<int,int>> v;
  set<pair<int,int>>s;
  for (int i = 0; i < n; ++i)
  {
    v.pb({a[i],b[i]});
    m[{a[i],b[i]}]++;
    s.insert({a[i],b[i]});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n-1; ++i)
  {
    if(v[i+1].S<v[i].S)return 0;
  }
  ll ans=1;
  for(auto i:s){
    if(m.count(i))ans=mul(ans,fac[m[i]]);
  }
  return ans;
}
void solve(){
  cin>>n;fact(n);
  set<pair<int,int> >s;
  for (int i = 0; i < n; ++i){cin>>a[i]>>b[i];s.insert({a[i],b[i]});}
  if(s.size()==1){cout<<0;return;}
  ll ans=fac[n];
  ans=sub(ans,add(f(a),f(b)));
  cout<<add(ans,f1());
  // cout<<ans;
}
int main()
{
    ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      // cout<<len;
      cout<<"\n";
    // }
    return 0;
}