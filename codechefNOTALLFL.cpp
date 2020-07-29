#include <bits/stdc++.h>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e5+3;
// const int N=300;
const int M = 1e8; // modulo
void solve(){
    int n,k;cin>>n>>k;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i)cin>>v[i];
    int M=0;
    for (int i = 1; i <= k; ++i)
    {
        int len=0,ind=0,m=-1;
        for (int j = 0; j < n; ++j)
        {
            while(v[j]==i and j<n)j++,len=0;
            while(v[j]!=i and j<n)len++,j++;
            j--;
            m=max(m,len);
        }
        // cout<<i<<" "<<m<<"\n";
        M=max(m,M);
        if(M==n)break;
    }
    cout<<M<<"\n";
}
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--)
    solve();cout<<"\n";
    return 0;
}