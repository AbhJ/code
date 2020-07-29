#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e4+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
int a[N],l[N],r[N];bool b[N];
void solve(){
  int n;cin>>n;
  string s;cin>>s;int l=-1,r=-1;
  for (int i = 1; i <= n; ++i)
  {
    if(s[i-1]=='1'){r=n-i;if(l==-1)l=i-1;}
  }
  if(l==-1 and r==-1)cout<<n;
  else
  cout<<2*n-2*min(l,r);
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