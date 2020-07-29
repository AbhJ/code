#include <bits/stdc++.h>
// #include <xeric>QC
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e5+10;
const ll M = 998244353 ; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
double a[N];
void solve(){
  int n;cin>>n;
  set<int>S;
  for (int i = 0; i < n; ++i)cin>>a[i];
  ll s=0,c=0;
  for (int i = 0; i < n; ++i)
  {
    if(floor(a[i])==ceil(a[i]))S.insert(i);
    s+=ceil(a[i]);
  }
  for (int i = 0; i < n; ++i)
  {
    if(S.count(i))cout<<(a[i]=floor(a[i]))<<" ";
    else if(s){s--,cout<<(a[i]=floor(a[i]))<<" ";}
    else cout<<(a[i]=floor(a[i])+1)<<" ";
  }
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