#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=5e1+10;
const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
vector<string>s;  
int n,m;
bool b=0;
int B=0;
set<pair<int,int>>a;
int ans;
bool vis[N][N];
int dfs(int i,int j){
  if(vis[i][j])return 0;
  if(s[i][j]=='.')return 0;
  vis[i][j]=1;
  return dfs(i,j+1)+dfs(i,j-1)+dfs(i-1,j)+dfs(i+1,j)+1;
}
void solve(){
  cin>>n>>m;
  s=vector<string>(n+2);
  string t;
  for (int i = 0; i < m+2; ++i)t+='.';
  s[0]=s[n+1]=t;
  for (int i = 1; i <= n; ++i)
  {
    cin>>s[i];
    s[i]='.'+s[i]+'.';
  }
  int x=0;
  // for (int i = 0; i < n+2; ++i)cout<<s[i]<<"\n";
  for (int i = 1; i <= n; ++i)
    for(int j=1;j<=m;j++)
      if(s[i][j]=='#')x++;
  if(x<=2){cout<<-1;return;}
  for (int i = 1; i <= n; ++i){
    for(int j=1;j<=m;j++)
      if(s[i][j]=='#'){
          memset(vis,0,sizeof(vis));
          s[i][j]='.';int y=-1;
          if(s[i+1][j]=='#')y=dfs(i+1,j);
          else if(s[i-1][j]=='#')y=dfs(i-1,j);
          else if(s[i][j+1]=='#')y=dfs(i,j+1);
          else if(s[i][j-1]=='#')y=dfs(i,j-1);
          // if(y==min(n,m)-1){cout<<0;return;}
          if(y!=x-1){cout<<1;return;}
          s[i][j]='#';
      }
  }
  cout<<2;
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