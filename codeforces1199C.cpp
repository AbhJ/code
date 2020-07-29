#include <bits/stdc++.h>
// #include <xeric>QC
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=4e5+10;
// const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
int a[N];
void solve(){
  int n,I;cin>>n>>I;int num=min(20,8*I/n);
  num=1<<num;
  for (int i = 0; i < n; ++i)
  {
    cin>>a[i];
  }
  sort(a,a+n);
  int l=0,r=0,ans=1e9+1,x=1;
  while(r<n){
    //x is number of distinct elements considered
    while(x>num){
      l++;if(a[l]!=a[l-1])x--;//whenever length becomes greater than 
      // feasible limit, we reduce it
    }
    ans=min(ans,n-(r-l+1));r++;
    if(a[r]!=a[r-1])x++;
  }
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