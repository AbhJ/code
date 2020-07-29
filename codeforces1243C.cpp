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
bool P(ll n){
  for(ll i=2;i<=sqrt(n);++i)
      {
          if(n%i==0)
          {
              return 0;
          }
      }
    return 1;
}
void solve(){
  ll n,i,a;cin>>n;
  if(n==1){cout<<1;return;}
  if(P(n)){cout<<n;return;}
  for (i = 2; i*i <= n; ++i)
    if(n%i==0){
      break;
    }
  a=i;
  while(i<n)i*=a;
  if(i==n){cout<<a;return;}
  cout<<1;
}
int main()
{
    ibs;cti;
    solve();
    cout<<"\n";
    return 0;
}