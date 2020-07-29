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
int n,m,A[3];
void solve(){
  int x,a,y,b;
  cin>>x>>a>>y>>b;
  if((a-1)/A[x]==(b-1)/A[y])cout<<"YES";
  else cout<<"NO";
}
int main()
{
    ibs;cti;
    cin>>n>>m;
    A[1]=n/__gcd(n,m);//number of compartment of 1
    A[2]=m/__gcd(n,m);//number of compartment of 2
    int t;cin>>t;
    while(t--){
      solve();
      cout<<"\n";
    }
    return 0;
}