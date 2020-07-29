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
using namespace std;int n=0;
void addo(unsigned ll A,unsigned ll B){
    while(B>0){
        n++;
        unsigned ll U = A ^ B;
        unsigned ll V = A & B;
        A = U;
        B = V * 2;
    }
    // return A;
}
#define watch(x) cout << (#x) << " is " << (x) << endl
int main()
{
    ibs,cti;
    int t;cin>>t;string a,b;
    while(t--){
        cin>>a>>b;n=0;
        ll A = strtoull (a.c_str (),NULL,2),B = strtoull (b.c_str (),NULL,2);;
        addo(A,B);
        cout<<n<<"\n";
    }
    return 0;
}