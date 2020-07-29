#include <bits/stdc++.h>
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
                        bool check=1;
                        for (int i = 1; i<=n ; ++i)
                        {
                            b[i]=b[i-1];
                            if(i-1 and a[i]>a[i-1]and check==1)b[i]++,check=0;
                            if(i-1 and a[i]<a[i-1] and check==0) b[i]--,check=1;
                        }
    while(q--){
                        int x=0,y=0;
                        int L,R;cin>>L>>R;
                        if((b[L+1]^b[R])!=0)cout<<"\nYES\n";else cout<<"\nNO\n";
    }

    return 0;   
}