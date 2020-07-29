#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=3e5+10;
const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
ll ans;
void solve(){
  ans=0;
  ll n,q;cin>>n>>q;
  ll par=0,a=0,b=0;
  while(q--){
    cin>>a>>b;
    ans+=abs(b-a)+abs(par-a);
    par=b;
  }
  cout<<ans;
}
int main()
{
    // ibs;cti;
    int t;cin>>t;
    while(t--){
      solve();
      // cout<<len;
      cout<<"\n";
    }
    return 0;
}