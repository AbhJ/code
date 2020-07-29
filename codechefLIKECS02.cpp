#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
int main()
{
    ibs;cti;int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for (int i = (n+1)/2; i <= (3*n-1)/2; ++i)
            cout<<i<<" ";
        cout<<"\n";
    }return 0;   
}