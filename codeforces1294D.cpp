#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
#define N 100000 
#define M 1000000007
int a[4*N+10];
int main()
{   
    ibs;cti;int m=0;
    int q,x;cin>>q>>x;
    while(q--){
        int y;cin>>y;
        a[y%x]++;
        while(a[m%x]>m/x) m++;
        cout<<m<<"\n";
    }
    return 0;
}