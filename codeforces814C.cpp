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
int ans[300][1600];
void solve(){
  int n,q;string s;
  cin>>n>>s>>q;
  std::vector<int> v[300];
  for(int c=0;c<300;c++){
    for (int i = 0; i < n; ++i){
      ll l=0;
      for(int j=i;j<n;j++)
      {
        if(s[j]!=c)l++;
        ans[c][l]=max(ans[c][l],j-i+1);
      }
    }
  for(int i=1;i<n;i++)ans[c][i]=max(ans[c][i],ans[c][i-1]);
  }
  while(q--){
    int a;char b;
    cin>>a>>b;
    cout<<ans[b][a]<<"\n";
  }
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