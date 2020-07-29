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
      std::vector<bool> movie(4,0),show(4,0);std::vector<int> cost;
      for (int i = 0; i < 4; ++i)
      {
      	if(show[i])continue;
      	int max=INT_MIN,mov=0;bool c=0;
      	for (int j = 0; j < 4; ++j)
      	{
      		if(max<v[i][j] and !movie[j])mov=j,max=v[i][j];
      	}
      	int j;
      	for (j = 0; j < 4; ++j)
      	{
      		if(max<v[j][mov] and !movie[mov])max=v[j][mov],c=1;
      	}
      	if(c=1 and max)show[j]=1,movie[mov]=1,cost.pb(max);
      	else 
      	if(max)
      		show[i]=1,movie[mov]=1,cost.pb(max);
      }
      sort(cost.begin(), cost.end(),greater<int>());
      int size=cost.size();ll ans=0;
      for (int i = 0; i < size; ++i)
      {
      	if(i==0)ans+=100*cost[i];
      	if(i==1)ans+=75*cost[i];
      	if(i==2)ans+=50*cost[i];
      	if(i==3)ans+=25*cost[i];
      }
      ans-=(4-size)*100;
      cout<<ans<<"\n";tot+=ans;
    }
    cout<<tot<<"\n";
    return 0;
}