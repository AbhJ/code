#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e5+10;
const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
int ans;
void solve(){
  string s;cin>>s;int t;cin>>t;
  while(t--){
    string S;cin>>S;
    char b=S[0],c=S[1];
    int B=0,C=0;
    for (auto i:s)
    {
      if(i==b)B++;
      else if(i==c)C++;
      else ans+=min(B,C),B=C=0;
    }
    ans+=min(B,C);
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