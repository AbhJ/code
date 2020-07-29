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
#define cot cout.tie(0)//solved using cyclic rotation
using namespace std;long long l[N],b[N],colour[100];ll C[100];
#define watch(x) cout << (#x) << " is " << (x) << endl
int main(){
    ibs;cti;
    int T;int j=0;
    cin>>T;
    while(T--){
        std::vector<pair<int,int>> v;
        int start=0;
        int n;cin>>n;cout<<n<<"\n";
        for (int i = 0; i < n-1; ++i)
            v.pb(make_pair(i+1,i+2));
        v.pb(make_pair(n,1));
        for (int i = 0; i != n; ++i)//rounds
        {
            cout<<"\n"<<n<<"\n";start=i;
            for (j=0; j<n ; ++j)//judge per round
            {
                cout<<"\n"<<j+1<<" "<<v[start].first<<" "<<v[start].second;
                start++;start%=n;
            }
            cout<<"\n";
        }
    }
    return 0;
}