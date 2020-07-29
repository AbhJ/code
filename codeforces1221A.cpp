#include <bits/stdc++.h>
#include <numeric>
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
  int n;cin>>n;ll ans=0;
  for (int i = 0; i < n; ++i)
  {
    int x;cin>>x;
    if(x>2048)continue;
    ans+=x;
  }
  if(ans>=2048)cout<<"YES";else cout<<"NO";
}
int main()
{
    ibs;cti;
    int t;cin>>t;
    // int x=1;
    while(t--){
      // cout<<"Case #"<<x<<": ";
      // x++;
      solve();
      cout<<"\n";
    }
    return 0;
}