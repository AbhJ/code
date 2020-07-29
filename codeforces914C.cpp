#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e3+10;
const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
ll mul(ll a,ll b){
  return ((a%M)*(b%M))%M;
}
ll add(ll a,ll b){
  return ((a%M)+(b%M))%M;
}
string s;ll k,n,i,j,c[N][N],order[N];
void f(){
  c[0][0]=1;
  for(i=1;i<N;i++){
        c[i][0]=c[i][i]=1;
        for(j=1;j<i;j++)
            c[i][j]=add(c[i-1][j-1],c[i-1][j]);
    }
}
void solve(){
  cin>>s>>k;n=s.length();f();
  if(k==0){cout<<1;return;}
  order[1]=0;
  for(i=2;i<N;i++)order[i]=1+order[bp(i)];
  ll ans=0;
  for(i=1;i<N;i++)
  {
    if(order[i]!=k-1)continue;
    int left=i;
    for(int j=0;j<n&&left;j++){
        if(s[j]=='1')ans=(ans+c[n-1-j][left])%M,left--;
    }
    if(!left)ans++;
  }
  if(k==1)ans--;
  cout<<ans;
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