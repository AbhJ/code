#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=3e5+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
void solve(){
  int n,m;cin>>n>>m;std::vector<ll> l(m+10),s(m+10,0);
  bool b=0;
  for (int i = 1; i <= m; ++i){cin>>l[i];if(l[i]+i-1>n)b=1;}
  for (int i = m; i  ; --i)
  {
    s[i]=s[i+1]+l[i];
  }
  if(s[1]<n)b=1;
  if(b){cout<<"-1";return;}
  for (ll i = 1; i <= m; ++i)
  {
    cout<<max(i,n-s[i]+1)<<" ";
  }
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