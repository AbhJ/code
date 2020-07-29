#include <bits/stdc++.h>
// #include <xeric>QC
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=3e5+10;
const ll M = 998244353 ; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
int n;string s;
void solve(){
  cin>>n;
  s="";
  int x=1;ll S=0;
  while(S+s.length()<n){//x is number were gonna add
    s+=to_string(x++);
   if(S+s.length()<n) S+=s.length();
  }
  cout<<s[n-S-1];
}
int main()
{
    ibs;cti;
    int t;cin>>t;
    while(t--){
      solve();
      // cout<<len;
      cout<<"\n";
    }
    return 0;
}