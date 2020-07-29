#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e6+3;
const ll M = 998244353; // modulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
pair<ll,std::vector<ll> > mal(std::vector<ll> v,ll n,ll m,ll pos){
    for (int i = pos+1; i <= n; ++i)
    {
        if(v[i]>v[i-1])v[i]=v[i-1];
    }
    for (int i = pos-1; i >0; --i)
    {
        if(v[i]>v[i+1])v[i]=v[i+1];
    }
    ll ans=0;
    for (int i = 1; i <= n; ++i)
    {
        ans+=v[i];
    }
    return {ans,v};
}
std::vector<ll> m(N),l(N),r(N),L(N),R(N),v1;
void solve(){
      int n;cin>>n;ll ma=0,mi=M,ind=-1;
      for(int i=1;i<=n;i++){
          cin>>m[i];
          int j=i-1;
          while(j>0 and m[j]>m[i])j=L[j];
          L[i]=j;
          l[i]=l[j]+m[i]*(ll)(i-j);
      }
      for(int i=n;i>0;i--){
          int j=i+1;
          while(j<=n and m[j]>m[i])j=R[j];
          R[i]=j;
          r[i]=r[j]+m[i]*(ll)(j-i);
          if(r[i]+l[i]-m[i]>ma){
              ma=r[i]+l[i]-m[i];
              ind=i;
          }
      }
      v1=mal(m,n,m[ind],ind).S;
      for (int i = 1; i <= n; ++i)
      {
          cout<<v1[i]<<" ";
      }
}
int main()
{   
    ibs;cti;
    // int t;cin>>t;
    // while(t--)
    solve(),cout<<"\n";
    return 0;
}