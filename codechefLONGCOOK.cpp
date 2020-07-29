#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e5+3;
const long M = 1000000007; // modulo 
ll dow(ll y, ll m, ll d)
{
  static ll t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
  y -= m < 3;
  return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}
int main()
{   
    ibs;cti;int t;cin>>t;
    while(t--){
      ll m1,y1,m2,y2;cin>>m1>>y1>>m2>>y2;
      ll ans=0;
      if(y2>y1+2020){
        ll num=0,i=y1;
        if(m1>2)y1++;
        if(m2<2)y2--;
        num=(y2-y1)/400;
        i=y1+num*400;
        ans=(num)*101;
        for (; i <= y2; ++i)
        {
          bool c=0;
          if(!i%400 )c=1;//leap
          if(!(i%4) and (i%100))c=1;
          if(6==dow(i,2,1))/*cout<<i<<"\n",*/ans++;
          else if(0==dow(i,2,1) and !c)/*cout<<i<<"\n",*/ans++;
        }
      }
      else for (ll i = y1; i <= y2; ++i)
      {
        if(y1*12+m1>i*12+2 or y2*12+m2<i*12+2){continue;}
        bool c=0;
        if(!i%400 )c=1;//leap
        if(!(i%4) and (i%100))c=1;
        // cout<<c<<"\n";
        if(6==dow(i,2,1))/*cout<<i<<"\n",*/ans++;
        else if(0==dow(i,2,1) and !c)/*cout<<i<<"\n",*/ans++;
      }
    cout<<ans<<"\n";
    }
    // cout<<day_of_week(2020,3,1);
    return 0;
}