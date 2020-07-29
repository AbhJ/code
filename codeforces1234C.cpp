#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e3+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
void solve(){
  int n;cin>>n;string s[2];
  cin>>s[0]>>s[1];
  int j=0;bool c=0;
  for(int i=0;i<n;i++){
    if(s[j][i]<'3'){
      if(i==n-1 and j==0)c=1;
      // i++;
    }
    else{
      if(i==n-1 and j==1)c=1;
      j=(j+1)%2;
      if(s[j][i]<'3')c=1;
    }
  }
  if(c)cout<<"NO";
  else cout<<"YES";
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