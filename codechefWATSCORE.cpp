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
        cin>>n;int p,s; std::vector<int> v(12);v[0]=0;
        for (int i = 0; i < n; ++i)
        {
            cin>>p>>s;
            if (v[p]<s and p<9)
                v[p]=s;
        }
        int sum=0;
        for (int i = 1; i < 12; ++i)
            sum+=v[i];
        cout<<sum<<"\n";
    }
    return 0;
}