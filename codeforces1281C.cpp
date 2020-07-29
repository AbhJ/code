#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
#define N 1000100
#define M 1'000'000'007
int main()
{
    ibs;cti;int t;cin>>t;while(t--){
        ll x,l;cin>>x;
        string S;cin>>S;l=S.length();
        std::vector<char> s(l);
        for (ll i = 0; i < l; ++i)
        {
            s[i]=S[i];
        }
        for (ll i = 1; i <=x; ++i){
           ll v=s[i-1]-'1';
           if(s.size()<x){
            std::vector<char> sub(s.begin()+i, s.end());
            for (ll i1 = 0; i1 < v; ++i1)
                s.insert(s.end(),sub.begin(), sub.end());
            }
            l=(l+(l-i)*v)%M;
           }
        cout<<(l%M+M)%M<<"\n";
    }
    return 0;
}