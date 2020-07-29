#include <bits/stdc++.h>
// #include <xeric>QC
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e1+10;
const ll M = 998244353 ; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
int n;string s;
vector<int>ans;
set<int>a[N];
int ind;char col[N];
void dfs(int u,int p=-1){
  if(ind>=n)return;
  if(col[u]==s[ind]){
    if(ind==0)ans.pb(u),ind++;
    else if(a[ans[ind-1]].count(u)==1)ans.pb(u),ind++;
    else return;
  }
  else return;
  for(auto i:a[u])dfs(i);
}
void f(int u,int v){
  a[u].insert(v),a[v].insert(u);
}
void solve(){
 cin>>s;n=s.length();
 for (int i = 0; i <= 9; ++i)
 {
   ans.clear(),ind=0;
   dfs(i);
   if(ind!=n)continue;
   for(auto j:ans)cout<<j;
  break;
 }
  if(ind!=n)cout<<-1;
}
int main()
{
    ibs;cti;
     for (int i = 0; i <=3; ++i)f(i,i+1);f(4,0);
    for (int i = 0; i <= 4; ++i)f(i,i+5);
    f(5,7),f(7,9),f(9,6),f(6,8),f(8,5);
    for (int i = 0; i <= 4; ++i)
    {
      col[i]=col[i+5]=(char)('A'+i);
    }
    // for (int i = 0; i <= 9; ++i)
    // {
    //   cout<<i<<"  ";
    //   for(auto j:a[i])cout<<j<<" ";
    //   cout<<"\n";
    // }
    int t;cin>>t;
    while(t--){
      solve();
      // cout<<len;
      cout<<"\n";
    }
    return 0;
}