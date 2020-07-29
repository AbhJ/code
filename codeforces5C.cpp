#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e6+10;
const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
string s;int n,d[N],c[N],ans;
void solve(){
  cin>>s;n=s.length();
  stack<int>S;c[0]=1;
  for (int i = 0; i < n; ++i)
  {
    if(s[i]=='('){S.push(i);continue;}
    if(S.empty()==0){
      int last=S.top();
      d[i]=i-last+1;
      if(last)d[i]+=d[last-1];
      S.pop();
      c[d[i]]++;
      ans=max(ans,d[i]);
    }
  }
  cout<<ans<<" "<<c[ans];
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