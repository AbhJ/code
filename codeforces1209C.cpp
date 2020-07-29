#include <bits/stdc++.h>
// #include <xeric>QC
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e5+10;
// const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
void solve(){
  int n;cin>>n;
  string s,t,a;cin>>s;int x=0;t=a=s;
  sort(t.begin(), t.end());
  for (int i = 0; i < n; ++i)
  {
    if(s[i]==t[x])s[i]='a',a[i]='1',x++;
  }
  for (int i = 0; i < n; ++i)
  {
    if(s[i]==t[x])s[i]='a',a[i]='2',x++;
  }
  if(x!=n)cout<<"-";else cout<<a;
}
int main()
{
    ibs;cti;
    int t;cin>>t;
    while(t--){
      solve();
      // cout<<len;
      cout<<"\n";
    }
    return 0;
}