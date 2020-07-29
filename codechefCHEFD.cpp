#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e5+10;
const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
void solve(){
  int n;cin>>n;std::vector<int> v(n);
  map<int,int>m[6];
  for (int i = 0; i < n; ++i)cin>>v[i];
  for (int i = 0; i < n; ++i)
  {
    while(v[i]%2==0)v[i]/=2,m[2][i]++;
    while(v[i]%3==0)v[i]/=3,m[3][i]++;
    while(v[i]%5==0)v[i]/=5,m[5][i]++;
  }
  int q;cin>>q;
  while(q--){
    int x;cin>>x;
    if(x==1){
      int l,r,p;cin>>l>>r>>p;
      for (int i = l-1; i <r; ++i)
      {
        m[p][i]=max(m[p][i]-1,0);
      }
    }
    else{
      int l,d;cin>>l>>d;m[2][l-1]=m[3][l-1]=m[5][l-1]=0;
      while(d%2==0)d/=2,m[2][l-1]++;
      while(d%3==0)d/=3,m[3][l-1]++;
      while(d%5==0)d/=5,m[5][l-1]++;
    }
  }
  for (int i = 0; i < n; ++i)
  {
    cout<<pow(2,m[2][i])*pow(3,m[3][i])*pow(5,m[5][i])<<" ";
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