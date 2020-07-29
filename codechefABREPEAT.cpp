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
using namespace std;int l[N];
#define watch(x) cout << (#x) << " is " << (x) << endl
int main(){
    ibs;cti; 
    int T;
    cin>>T;
    while(T--){
        ll n, k;char c;int last_b=INT_MIN,j=0;int count=0;
        cin>>n>>k;int count_a=0,count_b=0;
        std::vector<char> v;bool x=0;
        for (int i = 0; i < n; ++i)
        {
            cin>>c;
            if (c=='a')
                count_a++;
            if (c=='b'){
                count_b++;
                if (x)
                {
                    l[count]=j-last_b-1;
                }else{
                    l[count]=j;x=1;
                }
                last_b=j;
                count++;
            }
            if (c=='a'||c=='b'){
                v.pb(c);j++;
            }
        }
        for (int i = 1; i <= count; ++i){
            l[i]+=l[i-1];
        }
        ll sum_in_s=0;
        for(int i=0;i<count;i++)
            sum_in_s+=l[i];
        cout<<sum_in_s*k+k*(k-1)*count_a*count_b/2<<"\n";
    }
    return 0;
}