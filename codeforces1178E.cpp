#include <bits/stdc++.h>
// #include <xeric>QC
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e6+10;
const ll M = 998244353 ; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
string s;int n;set<int>S;
void solve(){
  cin>>s;n=s.length();s='#'+s;s+='@';
  int l=1,r=n;
  while(l<=r){
    //either left will match or right will math or itself will match
    if(s[l]==s[r])S.insert(l),S.insert(r),l++,r--;
    if(s[l+1]==s[r]){l++;continue;}
    else{r--;continue;}
  }
  for (int i = 1; i <= n; ++i)
  {
    if(S.count(i))cout<<s[i];
  }
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