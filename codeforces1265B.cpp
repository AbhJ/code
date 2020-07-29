#include <bits/stdc++.h>
#define ll long long
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define pb push_back
#define N 200015
struct table{
    int val,id;
}a[N];
bool cmp(table a,table b)
{
    return a.val>b.val;
}
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
int main()
{
    ibs;cti;int n,t;cin>>t;
    while(t--){
        cin>>n;int x;int a[n];
        for (int i = 0; i < n; ++i){
            cin>>x;a[x-1]=i;
        }int l=n-1,r=0;
        for (int i = 0; i < n; ++i){
            l=min(l,a[i]),r=max(r,a[i]);
            if(r-l-i)cout<<0;
            else cout<<1;
        }
        cout<<"\n";
    }
    return 0;   
}