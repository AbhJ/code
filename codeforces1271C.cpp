    #include <bits/stdc++.h>
    #define ll long long
    #define ibs ios_base::sync_with_stdio(false)
    #define cti cin.tie(0)
    #define pb push_back
    #define N 200015
    using namespace std;//coded by abhijay mitra
    ll a[201];
    #define watch(x) cout << (#x) << " is " << (x) << endl
    int main()
    {
        ibs;cti;int n;cin>>n;
        ll x,y; cin>>x>>y;ll r=0,u=0,l=0,d=0;ll xi,yi;
        for (int i = 0; i < n; ++i)
        {
            cin>>xi>>yi;if(xi>x) r++;if(xi<x) l++;
            if(yi>y)u++;if(yi<y) d++;
        }ll m;m=max(u,max(d,max(l,r)));
        cout<<m<<"\n";//number of student/customer
        if(m==r)
            cout<<x+1<<" "<<y;
        else if(m==l)
            cout<<x-1<<" "<<y;
        else if(m==u)
            cout<<x<<" "<<y+1;
        else if(m==d)
            cout<<x<<" "<<y-1; 
        return 0;
    }