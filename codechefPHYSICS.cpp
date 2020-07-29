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
void solve(){
  int n,f;cin>>n>>f;vector<int> h(n);
  std::map<int, ll> m;
  for (int i = 0; i < n; ++i)
  {
    cin>>h[i];
  }
  for (int i = 0; i < n; ++i)
  {
    int x=h[i];
    while(x%f==0)x/=f;
    m[x]++;
  }
  ll ans=0;
  for (auto i:m)
  {
    ans+=i.S*(i.S-1)/2;
  }
  cout<<ans;
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