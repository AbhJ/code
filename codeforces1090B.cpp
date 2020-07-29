#include <bits/stdc++.h>
// #include <xeric>QC
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e5+10;
const ll M = 998244353 ; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
int a[N],b[N],C;bool c;
void solve(){
  int n;cin>>n;
  for (int i = 0; i < n; ++i)
  {
    cin>>a[i];b[a[i]]++;
  }
  if(b[0]>=2)c=1;
  for (int i = 0; i < n; ++i)
  {
    if(i)if(b[i]>=2 and b[i-1]>=1)c=1;
    if(b[i]>=3)c=1;
    if(b[i]>=2)C++;
    if(C==2)c=1;
  }
  sort(a,a+n);ll s=0;
  for (int i = 0; i < n; ++i)
  {
    s+=a[i]-i;
  }
  if(s%2)c=1;
  if(!c)cout<<"cslnb";
  cout<<"sjfnb";
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