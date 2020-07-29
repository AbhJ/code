#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e5+3;
const long M = 1000000007; // modulo
int main()
{   
    ibs;cti;int t;cin>>t;
    while(t--){
      int n,p,i;cin>>n>>p;std::vector<int> v(n),a(n,0);bool c=0;
      for (i = 0; i < n; ++i)cin>>v[i];
      for (i = 0; i < n; ++i) if(p%v[i])c=1;
      if(!c)
      for (i = 0; i <n ; ++i) {
            for (int j = 0; j < i; ++j)
            {
                  if(v[i]%v[j]){c=1;break;}
            }
            if(c)break;
      }
      if(!c){cout<<"NO\n";continue;}
      for (i = n-1; i > -1; --i)
      {
            if(v[i]==1)continue;
            if(p%v[i]){
                  a[i]=p/v[i]+1;
                  break;
            }
            else if(p>v[i]){
                  a[i]=p/v[i]-1;p=v[i];
            }
      }
      cout<<"YES ";
      for (i = 0; i < n; ++i) cout<<a[i]<<" ";
      cout<<"\n";
    }
    return 0;
}