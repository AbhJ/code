#include <bits/stdc++.h>//solution by abhijay mitra
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
#define cot cout.tie(0)
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
int main(){
    ibs;cti; 
    int T;ll n,a,b=0;
    cin>>T;cout<<"\n";
    while(T--){
        cin>>n>>a>>b;ll temp;ll count2=0,counta=0;ll countb=0;
        for (int i = 0; i < n; ++i){
            cin>>temp;
            if (!(temp%a)||!(temp%b)){
                if (!(temp%(a*b))){
                    count2++;continue;
                }
                if (!(temp%a))
                    counta++;
                else countb++;
            }
        }
                if (!count2)
                    counta--;
                if (counta>=countb)
                    cout<<"BOB\n";else cout<<"ALICE\n";

                //we remove the highest multiple of a*b if avavilabe
                //otherwise we remove a or b's multiple
    }
    return 0;
}