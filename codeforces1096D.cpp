#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e3+10;
const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
ll h,a,r,d;
void solve(){
  int n;cin>>n;
  string s;cin>>s;
  for (int i = 0; i < n; ++i)
  {
    int cost;cin>>cost;
    if(s[i]=='h')h+=cost;
    if(s[i]=='a')a=min(h,a+cost);
    if(s[i]=='r')r=min(a,r+cost);
    if(s[i]=='d')d=min(r,d+cost);
  }
  cout<<d;
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