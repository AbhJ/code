#include <iostream>
using namespace std;
#define ll long long
#define pll pair<ll,pair<ll,ll> >
#include<queue>
#include<set>
#define mp make_pair
int main()
{
    int n, k;
    cin >> n >> k;
    int A[105000];
    set<pll > s;
    ll sum = 0;
    for(int i=1;i<=n; i++) {
        cin >> A[i];
        sum += A[i];
    }
    s.insert(mp(sum, mp(1, n)));
    while( k -- && !s.empty() ) {
        pll top = *s.rbegin();
        cout << top.first << " \n"[k == 0];
        s.erase(top );
        int l = top.second.first;
        int r = top.second.second;
        if( l != r ) {
            s.insert(mp(top.first-A[l], mp(l+1, r)));
            s.insert(mp(top.first-A[r], mp(l, r-1)));
        }
    }
    return 0;
}