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
  int n,m,k;cin>>n>>m>>k;std::vector<pair<int,int>> s1(k),v(k);
  for (int i = 0; i < k; ++i)
  {
    cin>>s1[i].F>>s1[i].S;
  }
  int x=1e9,y=1e9;
  for (int i = 0; i < k; ++i)
  {
    cin>>v[i].F>>v[i].S;
    v[i].F-=s1[i].F;
    v[i].S-=s1[i].S;
    x=min(x,v[i].F),y=min(y,v[i].S);
  }
  // for (int i = 0; i < n; ++i)
  // {
    
  // }
  string s;
  char c;
  for (int i = 0; i < m; ++i)
  {
    for (int j = 1; j < n; ++j)
    {
      if(i%2)s+="D",c='D';else s+="U",c='U';
    }
    if(i!=m-1)s+="R";
  }
  if(c=='U')
  for (int i = 0; i < m; ++i)
  {
    for (int j = 1; j < n; ++j)
    {
      if(i%2)s+="U";else s+="D";
    }
    if(i!=m-1)s+="L";
  }
  else
  for (int i = 0; i < m; ++i)
  {
    for (int j = 1; j < n; ++j)
    {
      if(i%2)s+="D";else s+="U";
    }
    if(i!=m-1)s+="L";
  }
  cout<<s.length()<<"\n";
  cout<<s;
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