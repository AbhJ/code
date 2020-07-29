#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e5+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
bool u[N];
vector<vector<int>> a;
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
int dfs(int x){
    // if(u[x])return;
    u[x]=1;
    // if(st)c[x]=i+1;
    for(int y:a[x])if(!u[y])
        return dfs(y);
    return x;
}

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
void solve(){
  int n,a=0,x=0;
  string s;cin>>n>>s;
  for (int i = 0; i < n; ++i){if(s[i]=='(')a++;}
  for (int i = 0; i < n; ++i)
  {
    if(s[i]=='?'){
      if(a<n/2)a++,s[i]='(';
      else s[i]=')';
    }
    if(s[i]=='(')x++;
    else x--;
    if(x<0){cout<<":(";return;}
    if(i==n-1 and x){cout<<":(";return;}
    if(i<n-1 and !x){cout<<":(";return;}
  }
  cout<<s;
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