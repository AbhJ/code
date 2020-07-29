#include <bits/stdc++.h>
#define ll long long
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
int main()
{
    ibs;cti;
    int r,c;cin>>r>>c;
    if(r==1 and c==1)cout<<0<<"\n";
    if(r==1 and c>1){
        for (int i = 0; i < r+c-1; ++i)
            cout<<i+2<<" ";
        cout<<"\n";return 0;
    }
    if(c==1 and r>1){
        for (int i = 0; i < r+c-1; ++i)
            cout<<i+2<<"\n";
        return 0;
    }
    if(r!=c)
    for (int i = 0; i < r; ++i){
        for (int i1 = 0; i1 < c; ++i1)
            cout<<(i+1)*(i1+r+1)<<" ";
        cout<<"\n";
    }
    if(r==c and r!=1)
    for (int i = 0; i < r; ++i){
        for (int i1 = 0; i1 < c; ++i1)
            cout<<(i+r+1)*(i1+1)<<" ";
        cout<<"\n";
    }
    return 0;   
}