#include <bits/stdc++.h>
#define ll long long int
#define N 200001
#define M 1000000007
#define f(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define po pop_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define cot cout.tie(0)//solved in time complexity o[n]
using namespace std;int l[N];int x[N];
#define watch(x) cout << (#x) << " is " << (x) << endl
int main(){
    ibs;cti; 
    int T;
    cin>>T;
    while(T--){
        int n;cin>>n;
        for (int i = 0; i < n; ++i)
        {
            cin>>l[i];if (!i)continue;
            x[i]=l[i]-l[i-1];
        }
// length =1 when we are in the ... serieselse 0
        bool length=0;
        for (int i = 0; i < n; ++i)
        {
            if ((x[i+1]==1)&&(length==0)&&(x[i+2]==1)&&(i<n-2))
            {
                cout<<l[i]<<"...";length=1;continue;
            }
            if (((length==1)&&(x[i+1]!=1)&&(i<n-1))||(length==0)||((length==1)&&(i==n-1)))
            {
                cout<<l[i];length=0;
            }
            if(!length&&(i<n-1)) cout<<",";
        }
        cout<<"\n";
        }
    return 0;
}