#include <bits/stdc++.h>
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define pb push_back
using namespace std;//coded by abhijay mitra
void solve(){
  int n,k;cin>>n>>k;int ans=n;
  for (int i = 0; i < n; ++i)
  {
    string s;cin>>s;set<int>S;
    for(auto j:s){
      if(j-'0'>k)continue;
      S.insert(j-'0');
    }
    if(S.size()!=k+1)ans--;
  }
  cout<<ans;
}
int main()
{   
    ibs;cti;
    solve(),cout<<"\n";
    return 0;
}