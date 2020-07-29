#include <bits/stdc++.h>
#include <numeric>
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
int a[N];
void solve(){
  int x=0;
  for (int i = 2; i < 6; ++i)
  {
    printf("? 1 %d\n",i);
    fflush(stdout);
    cin>>a[i];
    x=__gcd(x,a[i]);
  }
  if(x==30 or x==46)x=x>>1;
  printf("! %d ",x);
  ll p=x;
  for(int i=2;i<6;i++)printf("%d ",a[i]/x),p*=a[i]/x;
  printf("%lld\n",1LL*4*8*15*16*23*42/p);
}
int main()
{
    // ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      cout<<"\n";
    // }
    return 0;
}