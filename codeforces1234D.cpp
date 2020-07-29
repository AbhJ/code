#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=3e2+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
string s;
set<int>S[N];
void solve2(){
  int l,r;cin>>l>>r;l--,r--;
  int ans=0;
  for (int i = 'a'; i < 'z'+1; ++i)
  {
    if(S[i].lower_bound(l)!=S[i].upper_bound(r))ans++;
  }
  cout<<ans;
}
void solve1(){
  int p;char c;
  cin>>p>>c;
  p--;
  S[s[p]].erase(p);
  S[c].insert(p);
  s[p]=c;
}
int main()
{
    ibs;cti;
    cin>>s;
    int t;cin>>t;
    for (int i=0;i<s.length();i++)
    {
      S[s[i]].insert(i);
    }
    while(t--){
      // solve();
      int x;cin>>x;
      if(x==1)solve1();
      else solve2(),
      cout<<"\n";
    }
    return 0;
}