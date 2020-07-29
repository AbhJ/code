#include <bits/stdc++.h>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
void solve(){
     int a,b,x;cin>>a>>b;
     if((a>b) and (a-b)%2)x=2;
     else if((b>a) and !((b-a)%2))x=2;
     else if(b!=a)x=1;
     else x=0;
     cout<<x;
}
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--)
    solve(),cout<<"\n";
    return 0;
}