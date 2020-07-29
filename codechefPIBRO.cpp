#include <bits/stdc++.h>
#define ll long long int
#define N 100001
#define M 1000000007
#define f(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define po pop_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define cot cout.tie(0)//solved in time complexity o[pow(n,2)]
using namespace std;int h[N],t[N];
#define watch(x) cout << (#x) << " is " << (x) << endl
int main(){
    ibs;cti; 
    int T;//head array stores number of ones before i
          //tail array stores number of ones after i
    cin>>T;
    while(T--){
        int n;cin>>n;int k;cin>>k;string a;
        cin>>a;
        for(int i=0;i<n;i++){
            h[i]=0;t[i]=0;
        }
         for(int j = 1 ; j < n ; j++) {
            if (a[j - 1] == '1')
                h[j] = h[j - 1] + 1;
            else h[j] = 0;
        }
 
        for(int j = n - 2 ; j >= 0 ; j--) {
            if (a[j + 1] == '1')
                t[j] = t[j + 1] + 1;
            else t[j] = 0;
        }
        int ans=0,temp=0;
            for (int i = 0; i <= n-k; ++i)
            {
               temp=h[i]+t[i+k-1]+k;if(temp>ans)ans=temp;
            }
            cout<<"\n"<<ans<<"\n";        
            }
    return 0;
}