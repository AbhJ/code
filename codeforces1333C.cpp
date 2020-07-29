#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e6+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
void solve(){
  int n;cin>>n;
  std::map<ll, ll> m;
  m[0]=0;ll sum=0,ans=0,ind=-1;
  for (ll i = 1; i <= n; ++i)
  {
    int x;cin>>x;
    sum+=x;
    if(m.count(sum))ind=max(ind,m[sum]);
    ans+=i-ind-1;
    m[sum]=i;
  }
  cout<<ans;
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