#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e3+10;
const ll M = 1e9+7; // Mulo
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
ll solve(ll n){//return cumulative sum
  ll e=0,o=0;
  bool c=0;
  for (ll i = 0; (1LL<<i) <= n; ++i)
  {
    if(i%2==0)o+=1LL<<i,c=1;//add pow(2,i) odd num
    else e+=1LL<<i,c=0;//add pow(2,i) even num
  }
  ll r=n-e-o;//rest remaining numbers
  if(c)o+=r;else e+=r;//distribute as required
  return add(mul(o,o),mul(e,e+1));//return sum
}
int main()
{
    ibs;cti;
    // int t;cin>>t;
    // while(t--){
      ll l,r;cin>>l>>r;
      cout<<solve(r)-solve(l-1);
      cout<<"\n";
    // }
    return 0;
}