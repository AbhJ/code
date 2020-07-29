#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e6+10;
const ll M =  998244353; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
void solve(){
  int a,b;cin>>a>>b;
  if(b==1){cout<<0;return;}
  if((a%b)==0){cout<<0;return;}
  cout<<b-a%b;
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