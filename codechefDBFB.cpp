#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define M 1000000007
#define N 100000
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
ll c[N+10],d[N+10];
void ck(void) 
{
  ll i;
  c[2] = 0; 
  c[1] = 1;
  for (i = 3; i <= N+2; i++)c[i] = (c[i-1] + c[i-2])%M;
}
void dk(void) 
{ 
  ll i;
  d[1] = 0; 
  d[2] = 1;
  for (i = 3; i <= N+2; i++)d[i] = (d[i-1] + d[i-2])%M;
}
int main()
{
    ibs;cti;int t;cin>>t;dk();ck();
    while(t--){
        int n,m;cin>>m>>n;std::vector<ll> a(m+1,0),b(m+1,0);ll suma=0,sumb=0;
        for (int i = 1; i <= m; ++i){cin>>a[i];suma=(suma+a[i])%M;}
        for (int i = 1; i <= m; ++i){cin>>b[i];sumb=(sumb+b[i])%M;}
    	ll result=(suma*c[n]+sumb*d[n])%M;result=(result*m)%M;
	    cout<<result<<"\n";
    }return 0;   
}