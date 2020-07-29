#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e6+10;
const ll M =  998244353; // modulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
void solve(){
  int n;cin>>n;std::vector<bool> b(n,0);int d=-1;
  for (int i = 0; i < n; ++i)
  {
    int k;cin>>k;bool c=0;
    for (int j = 0; j < k; ++j)
    {
      int x;cin>>x;
      if(c==1)continue;
      if(b[x-1]==0){
        b[x-1]=1;c=1;
      }
    }
    if(d==-1)
    if(c==0)d=i+1;
  }
  if(d==-1){cout<<"OPTIMAL";return;}
  cout<<"IMPROVE\n"<<d<<" ";
  for (int i = 0; i < n; ++i)
  {
    if(b[i]==0){cout<<i+1;return;}
  }
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