#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e3+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
bool u[N];
std::vector<int> a[N];
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
int n,x,y,r=1;
int main()
{
      cin >> n;
      for (int i = 1; i < n; i ++) {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
      }
      for (; ;) {
        x = dfs(r);
        y = dfs(r);
        if (x == r) break;
        cout << "? " << x << ' ' << y << endl;
        cin >> r;
      }
      cout << "! " << r;
}