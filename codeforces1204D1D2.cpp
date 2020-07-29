#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e6+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
void solve(){
  string s;cin>>s;
  int ans=0;
  for(int i=s.length()-1;i>=0;i--){
    if(s[i]=='0')ans++;
    if(s[i]=='1'){
      if(ans==0)s[i]='0';
      else ans--;
    }
  }
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