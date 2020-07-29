#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e5+10;
const ll M =  998244353; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
void solve(){
    ll n,k;cin>>n>>k;ll i,j;
    for(i=1;i<=n;i++) if(k<=i*(i-1)/2) break;
    for(j=1;j<n-i+1;j++)cout<<"a";
    cout<<"b";
    for(j=1;j<=i*(i-1)/2-k;j++)cout<<"a";
    cout<<"b";
    for(j=1;j<=k-(i-1)*(i-2)/2-1;j++)cout<<"a";
}
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--)
      solve(),
      cout<<"\n";
    return 0;
}