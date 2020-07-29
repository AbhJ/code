#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
int main()
{
    int n,t,j=0,sum=0,ans=0;cin>>n>>t;std::vector<int> v(n,0);
    for (int i = 0; i < n; ++i)//taking input
    {
        cin>>v[i];sum+=v[i];
        while(sum>t)//j+1 is the i in the quesion
          sum-=v[j++];
        ans=max(ans,i-j+1);
    }
    cout<<ans<<"\n";
    return 0;   
}