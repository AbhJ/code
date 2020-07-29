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
int ans,X=1;
stack<int>s;
void ad(){
  int x;cin>>x;
  s.push(x);
}
void r(){
  if(s.empty()){X++;return;}
  if(X==s.top()){
    s.pop();
    X++;
    return;
  }
  ans++;
  while(!s.empty())s.pop();
  X++;
}
void solve(){
  int n;cin>>n;n=n<<1;
  while(n--){
    string str;cin>>str;
    if(str[0]=='a')ad();
    else r();
    // cout<<ans;
  }
  cout<<ans;
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