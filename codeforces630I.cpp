#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e5+3;
const long M = 1000000007; // modulo
// int m[2][N];//the grid
int main()
{   
    ibs;cti;
    ll n;cin>>n;
    cout<<2*4*3*(ll)pow(4,n-3)+(n-3)*4*3*3*(ll)pow(4,n-4)<<"\n";
    return 0;
}