#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=3e5+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
// bool u[N];int s;
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
// void dfs(int x){
//     if(u[x])return;
//     u[x]=1;s++;
//     // if(st)c[x]=i+1;
//     for(int y:a[x])if(!u[y])
//         dfs(y);
// }

ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
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
// struct b{int w,pos;}A[N];
int A[N];
void solve(){
  double d,D;cin>>d;
  if(!d){cout<<"Y 0 0";return;}
  if(d<4){cout<<"N";return;}
  cout<<"Y ";
  D=sqrt(d*(d-4));
  cout<<std::setprecision(25)<<(d+D)/2;
  cout<<" "<< std::setprecision(25)<<(d-D)/2;
}
int main()
{
    ibs;cti;
    int t;cin>>t;
    while(t--){
      solve();
      cout<<"\n";
    }
    return 0;
}