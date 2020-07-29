#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e6+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
int n,m;string s[N];
bool dfs(int x,int y){
  if(x+y==n+m-2)return 1;
  if(x>n-1 or y>m-1 or s[x][y]=='#')return 0;
  s[x][y]='#';//we block the first discoverd path to n-1,m-1
  return (dfs(x+1,y) or dfs(x,y+1));
}
void solve(){
  cin>>n>>m;
  for (int i = 0; i < n; ++i)
  {
    cin>>s[i];
  }
  if(!dfs(0,0)){cout<<"0";return;}s[0][0]='.';
  if(dfs(0,0))cout<<2;else cout<<1;
}
int main()
{
    ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      cout<<"\n";
    // }
    return 0;
}