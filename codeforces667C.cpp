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
bool dp[N][4];
void solve(){
  string s;cin>>s;int n=s.length();
  set<string>S;
  if(n-2>=5)S.insert(s.substr(n-2,2)),dp[n-2][2]=1;if(n-3>=5)S.insert(s.substr(n-3,3)),dp[n-3][3]=1;

  // if(s.substr(n-4,2)!=s.substr(n-2,2))S.insert(s.substr(n-4,2));
  for (int i = n-4; i >=5 ; --i)
  {
    if((dp[i+2][2] and s.substr(i,2)!=s.substr(i+2,2)) or dp[i+2][3])S.insert(s.substr(i,2)),dp[i][2]=1;
    if((s.substr(i,3)!=s.substr(i+3,3) and dp[i+3][3]) or dp[i+3][2])S.insert(s.substr(i,3)),dp[i][3]=1;
  }
  cout<<S.size()<<"\n";
  int x=0;
  for(auto i:S)cout<<i<<"\n",x++;
  // cout<<x;
}
int main()
{
    // ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      // cout<<len;
      cout<<"\n";
    // }
    return 0;
}