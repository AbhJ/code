#include <bits/stdc++.h>
// #include <numeric>
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
std::vector<pair<int,char>> v;
int n,m,k;
void p(int x,char c){
  int t=min(x,k);
  if(t==0)return;
  v.pb({t,c});
  k-=t;
}
void solve(){
  cin>>n>>m>>k;
  if(4*n*m-2*n-2*m<k){cout<<"NO";return;}
  m--,n--;
  cout<<"YES\n";
  for (int i = 1; i <= n; ++i)
  {
    p(m,'R'),p(m,'L'),p(1,'D');
  }
  for (int i = 1; i <= m; ++i)
  {
    p(1,'R'),p(n,'U'),p(n,'D');
  }
  p(m,'L'),p(n,'U');
  cout<<v.size()<<"\n";
  for (auto i:v)
  {
    cout<<i.F<<" "<<i.S<<"\n";
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