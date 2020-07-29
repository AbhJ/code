#include <bits/stdc++.h>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
void solve(){
     int n,m;cin>>n>>m;
      string s;cin>>s;std::vector<int> p(m),count(n),ans(26);
      for (int i = 0; i < m; ++i)cin>>p[i];
      for (int i = 0; i < m; ++i)count[p[i]-1]++;
      for (int i = n-1; i > 0; --i)count[i-1]+=count[i];
      for (int i = 0; i < n; ++i)
      {
        ans[s[i]-'a']+=count[i]+1;
      }
      for (int i = 0; i < 26; ++i)cout<<ans[i]<<" ";
}
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--)
    solve(),cout<<"\n";
    return 0;
}