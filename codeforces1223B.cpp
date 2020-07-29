#include <bits/stdc++.h>
// #include <xeric>
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
string a,b;int n;set<char>s[2];
void solve(){
  cin>>a>>b;n=a.length();bool c=0;
  s[0].clear();s[1].clear();
  for(auto i:a)s[0].insert(i);
  for(auto i:b)s[1].insert(i);
  for(auto i:s[0])for(auto j:s[1])if(i==j)c=1;
  if(c==0)cout<<"No";else cout<<"Yes";
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