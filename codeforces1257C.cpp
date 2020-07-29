#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
#define N 100000 
#define M 1000000007
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--){
    	int n;cin>>n;std::vector<int> occur(n,-3);int ans=INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            int x;cin>>x;
            if(occur[x-1]!=-3)
            ans=min(ans,i-occur[x-1]+1);
            occur[x-1]=i;
        }
        if(ans!=INT_MAX)
        cout<<ans<<"\n";
        else cout<<"-1\n";
    }
    return 0;
}