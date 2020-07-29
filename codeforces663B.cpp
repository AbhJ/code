#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=5e3+10;
const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
ll b,c;
void solve(){
  ll n;cin>>n;
  while(b<n){
    c+=5;
    int x=c;while(x%5==0)b++,x/=5;
  }
  if(b>n){cout<<0;return;}
  cout<<"5\n";
  for (int i = c; i < c+5; ++i)
  {
    cout<<i<<" ";
  }
}
int main()
{
    // ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      // cout<<len;
      cout<<"\n";
    // }
    return 0;
}