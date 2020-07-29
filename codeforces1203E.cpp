#include <bits/stdc++.h>
// #include <xeric>QC
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e5+10;
// const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
int a[N];
bool cmp(int a,int b){return a>b;}
void solve(){
  int n;cin>>n;
  for (int i = 0; i < n; ++i)
  {
    cin>>a[i];
  }
  int ans=0,ok=1e9+1;
  sort(a,a+n,cmp);
  for (int i = 0; i < n; ++i)
  {
    ans++;
    if(a[i]+1<ok)ok=a[i]+1;
    else if(a[i]<ok)ok=a[i];
    else if(a[i]<ok+1 and a[i]!=1)ok=a[i]-1;
    else ans--;
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