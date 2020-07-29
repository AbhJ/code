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
// int i,a[10],ans;
void solve(){
  int n,m;cin>>n>>m;
  for (int i = 0; i < n; ++i)
  {
    for(int j=0;j<m-1;j++){
      /*if(j%2==0)*/cout<<"B";
      // else cout<<"W";
    }
    if(i!=n-1)cout<<"W";
    else cout<<"B";
  cout<<"\n";
  }
}
int main()
{
    ibs;cti;
    int t;cin>>t;
    while(t--){
      solve();
      // cout<<"\n";
    }
    return 0;
}