#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e3+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
int c[N][N];
char s[N][N];
void solve(){
  int n,m;cin>>n>>m;/*string s[n+1];*/
  for (int i = 1; i <= n; ++i)
  {
    scanf("%s",s[i]+1);
  }
  // int c[n][m];memset(c,1,sizeof(c));
  for (int i = n; i ; --i)
  {
    for(int j=1;j<=m;j++)
      if(s[i][j]==s[i+1][j])c[i][j]=1+c[i+1][j];
      else c[i][j]=1;
  }
  ll ans=0,l=0;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
      int v=c[i][j];
      if(i+v*3-1<=n and c[i+v][j]==v and c[i+v*2][j]>=v){
        if(v and s[i][j]==s[i][j-1] and c[i][j]==c[i][j-1] and s[i+v][j]==s[i+v][j-1] and s[i+v*2][j]==s[i+v*2][j-1])
        l++;
        else l=1;
      }
      else l=0;
      ans+=l;
    }
  cout<<ans;
}
int main()
{
    // ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      cout<<"\n";
    // }
    return 0;
}