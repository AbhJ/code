#include <bits/stdc++.h>
#define double long double
#define int long long int
#define ll int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
#define koto_memory(a) cout<<(sizeof(a)/1048576.0)<<" MB";
#define res(v) v.resize(unique(v.begin(), v.end()) - v.begin());
#define cnt_res(v) std::distance(v.begin(),std::unique(v.begin(), v.end())); 
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x)     x.begin(), x.end()
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int a[N],n;
int mex() {
  map<int, bool> m;
  rep(i,0,n-1)m[a[i]] = true;
  rep(i,0,n-1){
    if (!m[i]) return i;
  }
  return n;
}
void solve(){
  cin>>n;set<int>q;vi ans;
  rep(i,0,n-1){cin>>a[i];if(a[i]!=i)q.insert(i);}
  //q contains indices which hasn't been decided
  while(q.empty()==0){
    int x=*q.begin();
    int m=mex();
    if(m==n){
      a[x]=m;
      ans.pb(x);
    }
    else{
      a[m]=m;
      ans.pb(m);
      q.erase(m);
    }
  }
  cout<<ans.size()<<"\n";
  for(auto i:ans)cout<<i+1<<" ";
}
int32_t main()
{
  ibs;cti;
  // solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}