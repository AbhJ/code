#include <bits/stdc++.h>//DYNAMO
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
#define N 100010
ll a[N],b[N],c[N];
int main()
{
    int n,q;cin>>n>>q;
    for (int i = 1; i <= n; ++i)
        cin>>a[i];
                        // cout<<"\nb\n";
                        for (int i = 1; i <= n; ++i)
                        {
                            b[i]=b[i-1];
                            if(a[i]>a[i-1]) b[i]++;
                            // cout<<b[i]<<" ";
                        }
                        c[n+1]=0;
                        // cout<<"\nc\n";
                        for (int i = n; i >0; --i)
                        {
                            c[i]=c[i+1];
                            if(a[i]>a[i+1]) c[i]++;
                        }
                        int x=0,y=0;
                        // for (int i = 1; i <= n; ++i)
                        // {
                        //     cout<<c[i]<<" ";
                        // }
    while(q--){         
                        x=0;y=0;
                        int L,R;cin>>L>>R;
                        for (int i = L; i < R; ++i)
                        {
                            if(b[i+1]==b[i])continue;
                            while(b[i+1]>b[i])
                                i++;
                            x++;
                        }
                        for (int i = L; i < R; ++i)
                        {
                            if(c[i+1]==c[i])continue;
                            while(c[i+1]<c[i])
                                i++;
                            y++;
                            // cout<<i<<" ";
                        }
                        if(x==y)cout<<"\nYES\n";else cout<<"\nNO\n";
                        // cout<<x<<" "<<y<<"\n";
    }

    return 0;   
}