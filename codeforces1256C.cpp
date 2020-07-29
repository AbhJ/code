    #include <bits/stdc++.h>
    #define ll long long
    #define ibs ios_base::sync_with_stdio(false)
    #define cti cin.tie(0)
    #define pb push_back
    #define N 200015
    using namespace std;//coded by abhijay mitra
    ll a[1009];
    #define watch(x) cout << (#x) << " is " << (x) << endl
    int main()
    {
        ibs;cti;
        int n,m,d;cin>>n>>m>>d;ll c[m+2];ll sum=0,pos=0;
        for (int i = 1; i <=m; ++i){
            cin>>c[i];
            sum+=c[i];
        }
        for (int i = 1; i <= m; ++i)//plank wise analysis
        {
            if (pos+d+sum>n+1)//I cannot jump d cells to first location, it should come close
            {
                for (int j = pos+1; j < c[i]+pos+1; ++j)//when i am on plank
                    a[j]=i;
                sum-=c[i];pos+=c[i];
            }
            else{
                for (int j = pos+d; j < c[i]+pos+d; ++j)
                    a[j]=i;
                sum-=c[i];pos+=d-1+c[i];
            }
        }
        if(pos+d>n){
            cout<<"YES\n";
            for (int i = 1; i < n+1; ++i)
                cout<<a[i]<<" ";
            cout<<"\n";
        }
        else cout<<"NO\n";
        return 0;   
    }