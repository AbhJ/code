#include <bits/stdc++.h>
// #include <xeric>QC
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e3+10;
const ll M = 998244353 ; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
int l,r;bool c=1,f;
bool ch[N];
vector<pair<int,int> > v;
void s(){
  for (int i = l; i <r; ++i)
  {
    ch[i]=1;
  }
}
void u(){
  v.pb({l,r});
}
void solve(){
  int n,m;cin>>n>>m;
  while(m--){
    bool x;cin>>x;
    cin>>l>>r;
    if(x==1)s();
    else u();
  }
  for (auto i:v)
  {
    c=0;
    for(int j=i.F;j<i.S;j++){
      if(ch[j]==0)c=1;
    }
    if(c==0){cout<<"NO";return;}
  }
  int x=n;
  cout<<"YES\n";
  for (int i = 1; i <= n; ++i)
  {
    cout<<x<<" ";
    if(ch[i]==0)x--;
  }
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