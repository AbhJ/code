#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e6+3;
const ll M =  998244353; // modulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
int b[N];
void solve(){
 int n;cin>>n;std::vector<int> v(n);memset(b,0,sizeof(b));
 for (int i = 0; i < n; ++i)cin>>v[i];
 int m;cin>>m;std::vector<int> p(m),s(m);
 for (int i = 0; i < m; ++i)cin>>p[i]>>s[i],b[s[i]]=max(b[s[i]],p[i]);
 for (int i = n-1; i >-1; --i)b[i]=max(b[i],b[i+1]);
 int pos=0,ans=0;
 while(pos<n){
  ans++;int cur=pos;int ma=0;
  while(1){
    ma=max(ma,v[cur]);if(ma>b[cur-pos+1])break;cur++;
  }
  if(cur==pos){cout<<-1;return;}
  pos=cur;
 }
 cout<<ans;
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