#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e3+10;
const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
void solve(){
  int n,m;cin>>n>>m;
  if(n and m){
    if(n>=m){
      if(2*sqrt(m*m+n*n)+n<sqrt(m*m+n*n)+2*sqrt((m-1)*(m-1)+n*n))
        cout<<"0 1\n"<<n<<" "<<m<<"\n0 0\n"<<n<<" "<<m-1;
      else cout<<"0 0\n"<<n<<" "<<m<<"\n0 "<<m<<"\n"<<n<<" 0";
    }
    else{
      if(2*sqrt(m*m+n*n)+m<sqrt(m*m+n*n)+2*sqrt(m*m+(n-1)*(n-1)))
        cout<<"1 0\n"<<n<<" "<<m<<"\n0 0\n"<<n-1<<" "<<m;
      else cout<<"0 0\n"<<n<<" "<<m<<"\n"<<n<<" 0\n0 "<<m;
    }
  }
  else if(n)cout<<"1 0\n"<<n<<" 0\n0 0\n"<<n-1<<" 0";
  else cout<<"0 1\n0 "<<m<<"\n0 0\n0 "<<m-1;
}
int main()
{
    // ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      // cout<<len;
      // cout<<"\n";
    // }
    return 0;
}