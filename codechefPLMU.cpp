#include <bits/stdc++.h>
#define ll long long int
#define N 1000000
#define M 1000000007
#define f(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define po pop_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define cot cout.tie(0)//solved by abhijay mitra in time O(n)
using namespace std;int v[N];
#define watch(x) cout << (#x) << " is " << (x) << endl
int main()
{
    ibs,cti;
    int t;cin>>t;int a,b,n;
    while(t--){
        cin>>n;
        ll x;ll count0=0,count2=0;
        for(int i=0;i<n;i++){
            cin>>x;
            if(x==0)
                count0++;
            if (x==2)
                count2++;
        }
        cout<<(count0*(count0-1)/2)+(count2*(count2-1)/2)<<"\n";
    }
    return 0;
}