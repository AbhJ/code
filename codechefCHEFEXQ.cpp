#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e6+10,b=1000;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
void solve(){
  int n,q;cin>>n>>q;std::vector<int> v(n+1,0),x(n+1,0);
  for (int i = 1; i <= n; ++i)
  {
    cin>>v[i];x[i]=v[i];
    if(i)x[i]^=x[i-1];

  }
  int nb=(n+b-1)/b+1;
  int f[nb][N],a[nb]={0},j=0;memset(f,0,sizeof(f));
  for (int i = 1; i <= n; ++i)
  {
    f[i/b][x[i]]++;
  }
  while(q--){
    int t,i,X;cin>>t>>i>>X;
    int bn=i/b;
    if(t==1){
      for(j=bn+1;j<nb;j++)a[j]=(a[j]^v[i]^X);
      for(j=i;j<min(n+1,b*(bn+1));j++)f[bn][x[j]]--,x[j]=(x[j]^X^v[i]),f[bn][x[j]]++;
      v[i]=X;
    }
    else{
      int s=0;
      for(j=0;j<bn;j++)s+=f[j][a[j]^X];
      for(j=b*bn;j<=i;j++)if((x[j]^a[bn])==X)s++;
      cout<<s<<"\n";  
    }
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