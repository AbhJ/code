#include <bits/stdc++.h>
#define ll long long int
#define N 1000009
#define M 1000000007
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define po pop_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define cot cout.tie(0)
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
int main()
{
    ibs;cti;
    int t;cin>>t;cout<<"\n";
    while(t--){
        int k;cin>>k;std::vector<int> v(k);ll stem=1,leaf;
        bool check=0;
        for (int i = 0; i < k; ++i){
           cin>>leaf;//in that stem
           if(leaf>stem and check==0)
                check=1;
           else if(check==0){
            stem=(stem-leaf)*2;
            }
        }
        if(check==0 and stem==0)
            cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}