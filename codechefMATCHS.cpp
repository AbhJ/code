#include <bits/stdc++.h>
#define ll long long int
#define N 1000009
#define M 1000000007
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define po pop_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define cot cout.tie(0)
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
int main()
{
    ibs;cti;
    int t;cin>>t;cout<<"\n";
    while(t--){
        ll n,m;cin>>n>>m;
        ll chance=0;
        while(n and m){
            if(n>2*m or m>2*n)
                {chance++;break;}
            if(n>m)
                n%=m;
            else m%=n;
            chance++;
        }
        if(!(chance%2))cout<<"Rich\n";
        else cout<<"Ari\n";
    }
    return 0;
}