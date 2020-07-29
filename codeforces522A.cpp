#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e5+10;
const ll M =  1e9+7; // modulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
// int A[N];
// bool u[N];
// vector<vector<pair<int,int>> > a;
// void bfs(int s) {
//   d[s] = 0;
//   queue<int> q;
//   q.push(s);
//   while (!q.empty()) {
//     int v = q.front();q.pop();
//     for (auto to : a[v]) {
//       if (d[to] == -1) {
//         d[to] = d[v] + 1;
//         q.push(to);
//       }
//     }
//   }
// }
// ll ans=INT_MIN;
// ll dp[N];
// int dfs(int u,int v=-1){
//     // ll d=c[u];
//     // ans=max(ans,d);
//     // if(u[x])return;
//     // u[x]=1;
//     // if(st)c[x]=i+1;
//     if(A[u]<v)return 0;
//     int x=0;
//     for(auto y:a[u]){

//     // if(u==0)cout<<x+1<<"\n";
//         // int y=b.F;ll C=b.S;
//         // if(y.F==v)continue;
//       //second is total value on path
//         x+=dfs(y.F,max(0,y.S+v));
//         // ans=max(ans,x+d-C);
//         // if(x%=2)ans++;
//         // t=max(x,t);
//         // d=max(d,win+c[u]-C);
//     }
//     // dp[u]=max(dp[u],c[u]);
//     return x+1;
// }

// ll powM(ll b, int p) {
//   ll r=1;
//   for(; p; b=b*b%M, p/=2)
//     if(p&1)
//       r=r*b%M;
//   return r;
// }
// ll powM(ll a,ll b)
// {
//   ll ans=1;
//   while(b)
//   {
//     if(b&1LL)ans=ans*a%M;
//     a=a*a%M;
//     b>>=1;
//   }
//   return ans;
// }
// ll s,side,x,y;
void solve(){
  int n;cin>>n;int ans=0;
  std::map<string, int> m;
  m["polycarp"]=1;
  for (int i = 0; i < n; ++i)
  {
    string a,b,c;cin>>a>>b>>c;
    for (int i = 0; i < a.length(); ++i)
    {
      a[i]=tolower(a[i]);
    }
    for (int i = 0; i < c.length(); ++i)
    {
      c[i]=tolower(c[i]);
    }
    ans=max(ans,m[c]+1);
    m[a]=1+m[c];
  }
  cout<<ans;
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