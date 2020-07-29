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
        std::vector<int> v(3);
        for (int i = 0; i < 3; ++i)
            cin>>v[i];
        sort(v.begin(), v.end());
        v[0]=v[2]-v[0];v[1]=v[2]-v[1];
        int x=v[0]+v[1],n;
        cin>>n;n-=x;
        if(n<0 or n%3){cout<<"NO\n";continue;}
        cout<<"YES\n";
    }
    return 0;
}