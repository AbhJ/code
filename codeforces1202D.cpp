#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e3+10;
const ll M = 998244353; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
void solve(){
  ll n;cin>>n;
  ll i=0;
  while((i*i-1)/2<=n)i++;
  i--;
  ll rem=n-i*(i-1)/2;
  cout<<133;
  while(rem--)cout<<7;while(i-->2)cout<<3;cout<<7;
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