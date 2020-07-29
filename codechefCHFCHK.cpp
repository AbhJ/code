#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
#define N 100000
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int mina=INT_MAX,x;
        for (int i = 0; i < n; ++i)
            cin>>x,mina=min(mina,x);
        cout<<mina<<"\n";
    }
    
    return 0;
}