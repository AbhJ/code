#include <bits/stdc++.h>
#define ll long long int
#define N 100500
#define M 1000000007
#define f(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define po pop_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define cot cout.tie(0)
using namespace std;int n=0;
void addo(bitset<N> a, bitset<N> b){
    while(1){
        ll count1=b.count();
        if (count1==0)
        {
            break;
        }
        bitset<N> U =a^b;
        bitset<N> V=a&b;
        a=U;b=V<<1;
        n++;count1=b.count();
        ll index=0;
        if (count1==1)
        {
            index=b._Find_first();
            for (int i = index; a[i]==1; ++i)
            {
                n++;
            }
            n++;
            break;
        }
        // cout<<a<<"\n"; cout<<b<<"\n";
    }
    // cout<<A<<"\n"; cout<<B<<"\n";
}
#define watch(x) cout << (#x) << " is " << (x) << endl
int main()
{
    ibs,cti;
    int t;cin>>t;string a,b;cout<<"\n\n";
    while(t--){
        cin>>a>>b;n=0;ll size;
        // the below snippets are to make length of a and b same
        bitset<N> A(a),B(b);
        addo(A,B);cout<<n<<"\n";
    }
    return 0;
}