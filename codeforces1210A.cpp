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
bool a[10][10];
void solve(){
  int n,m;cin>>n>>m;
  for (int i = 0; i < m; ++i)
  {
    int x,y;cin>>x>>y;a[x][y]=a[y][x]=1;
  }
  int mi=1e9;
  for (int i = 1; i <= 7; ++i)
  {
    for(int j=1;j<=7;j++){
      int c=0;
      for(int k=1;k<=7;k++){
        if(a[i][k] & a[k][j])c++;
      }
      mi=min(mi,c);
    }
  }
  if(n<=6)cout<<m;else cout<<m-mi;
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