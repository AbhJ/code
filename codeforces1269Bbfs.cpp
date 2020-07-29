#include <bits/stdc++.h>
#define ll long long
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
int main()
{
    ibs;cti;
    int n;ll m;cin>>n>>m;std::vector<ll> a(n),b(n,0);bool Check=0;
    ll maxa=0,mina,maxb=0,minb;
    for (int i = 0; i < n; ++i){
        cin>>a[i];maxa=max(a[i],maxa);mina=min(a[i],mina);
    }
    for (int i = 0; i < n; ++i){
        cin>>b[i];maxa=max(a[i],maxa);mina=min(a[i],mina);
    }
    ll i=0;sort(a.begin(), a.end()),sort(b.begin(), b.end());
    for (i = 0;; ++i)
    {
        if(a==b){cout<<i<<"\n";return 0;}
        for (int j = 0; j < n; ++j)
        {
            b[j]--;if(b[j]==-1)b[j]=m-1;maxb=max(b[j],maxb);minb=min(b[j],minb);
        }
        if(maxa==maxb and mina==minb)sort(a.begin(), a.end()),sort(b.begin(), b.end());
    }
}