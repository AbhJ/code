#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e6+10;
const ll M =  998244353; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
void solve(){
  int a,b,c;cin>>a>>b>>c;
  int ans = 1e9;
    int A,B,C;
    for (int A1 = 1; A1 <= 2 * a; ++A1) {
      for (int B1 = A1; B1 <= 2 * b; B1 += A1) {
        for (int i = 0; i < 2; ++i) {
          int C1 = B1 * (c / B1) + i * B1;
          int res = abs(A1 - a) + abs(B1 - b) + abs(C1 - c);
          if (ans > res) {
            ans = res;
            A = A1;
            B = B1;
            C = C1;
          }
        }
      }
    }
    cout<<ans<<"\n"<<A<<" "<<B<<" "<<C;
}
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--){
      solve();
      cout<<"\n";
    }
    return 0;
}