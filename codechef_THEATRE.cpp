#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e5+3;
const long M = 1000000007; // modulo
// int m[2][N];//the grid
ll v[4][4];//each vector is for a slot stores number of people per movie
int main()
{   
    ibs;cti;int t;cin>>t;ll tot=0;
    while(t--){
      memset (v,0,4*sizeof(v));
      ll n;cin>>n;
      for (int i = 0; i < n; ++i)
      {
      	char c;int slot,m;
      	cin>>c>>slot;
      	if(c=='A')m=0;
      	if(c=='B')m=1;
      	if(c=='C')m=2;
      	if(c=='D')m=3;
      	if(slot==12)slot=0;
      	if(slot==3)slot=1;
      	if(slot==6)slot=2;
      	if(slot==9)slot=3;
      	v[slot][m]++;
      }
      std::vector<bool> movie(4,0),show(4,0);std::vector<ll> cost;
      ll ans=INT_MIN,a=0;
      for (int i = 0; i < 4; ++i)
      {
            for(int j=0;j<4;j++){
                  if(i==j)continue;
                  for (int k = 0; k < 4; ++k)
                  {
                        if(k==i or k==j)continue;
                        for (int l = 0; l < 4; ++l)
                        {
                              if(l==i or l==j or l==k)continue;
                              std::vector<ll> t;
                              t.pb(v[0][i]);
                              t.pb(v[1][j]);
                              t.pb(v[2][k]);
                              t.pb(v[3][l]);
                              sort(t.begin(), t.end(),greater<int>());int z=0;
                              a=100*t[0]+75*t[1]+50*t[2]+25*t[3];
                              for (int i1 = 0; i1 < 4; ++i1)
                                    if(!t[i1])z++;
                              a-=z*100;
                              ans=max(a,ans);
                        }
                  }
            }
      }
      cout<<ans<<"\n";tot+=ans;
    }
    cout<<tot<<"\n";
    return 0;
}