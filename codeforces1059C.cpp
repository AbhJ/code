#include <bits/stdc++.h>
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
void solve(){
    int n,j=1;cin>>n;
    while(n){
        for(int i=1;i<=(n+1)/2;i++)cout<<j<<" ";
        if(n==3) {cout<<j*3<<" ";break;}
        n/=2;j=j<<1;
    }
}
int main()
{   
    ibs;cti;
    solve();cout<<"\n";
    return 0;
}