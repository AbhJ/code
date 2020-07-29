#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e5+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
int d[N],c[N],v[3][N];std::vector<int> e[N];
bool u[N];
ll dfs(int x,int i,int pls=1,bool st=0){
	u[x]=1;
	if(st)c[x]=i+1;
	for(int y:e[x])if(!u[y])
		return v[i][x]+dfs(y,(i+pls)%3,pls,st);
	return v[i][x];
}
void solve(){
  int n;cin>>n;
  for(int j=0;j<3;j++)for (int i = 1; i <= n; ++i)
  {
  	cin>>v[j][i];
  }
  
  for (int i = 1; i < n; ++i)
  {
  	int x,y;cin>>x>>y;
  	d[x]++,d[y]++;
  	if(d[x]>2){cout<<-1;return;}
  	if(d[y]>2){cout<<-1;return;}
  	e[x].pb(y),e[y].pb(x);
  }
  int x=0,y=0;
  for (int i = 1; i <= n; ++i)
  {
  	if(d[i]==1){x=i;break;}
  }
  ll a[6];
  for (int i = 0; i < 6; ++i)
  {
  	a[i]=dfs(x,i%3,i/3+1);
  	if(a[i]<a[y])y=i;
  	memset(u,0,sizeof(u));
  }
  cout<<a[y]<<"\n";
  dfs(x,y%3,y/3+1,1);
  for (int i = 1; i <=n ; ++i)
  {
  	cout<<c[i]<<" " ;
  }
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