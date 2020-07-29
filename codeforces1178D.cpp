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
bool p(int n){
  for(int i=2;i<=sqrt(n);++i)
  {
      if(n%i==0)
      {
          return 0;
      }
  }
  return 1;
}
int n,m;
void solve(){
  cin>>n;m=n;
  while(!p(m))m++;cout<<m<<"\n";
  cout<<"1 "<<n<<"\n";
  for (int i = 1; i < n; ++i)
  {
    cout<<i<<" "<<i+1<<"\n";
  }
  for (int i = 1; i <=m-n ; ++i)
  {
    cout<<i<<" "<<i+n/2<<"\n";
  }
}
int main()
{
    ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      // cout<<len;
      // cout<<"\n";
    // }
    return 0;
}