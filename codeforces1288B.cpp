#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
#define N 1000100
int main()
{
    ibs;cti;int t;cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        ll sum=0,x=-9;
        for (ll i = 9; i <= b; i=x+9)
            sum+=a,x=i*10;
        cout<<sum<<"\n";
    }
    return 0;
}