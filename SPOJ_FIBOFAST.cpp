#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e5+3;
const long M = 1000000007; // modulo
// int m[2][N];//the grid
map<long long, ll> F;
vector<ll> T[1234];

long long f(long long n, int Depth) {
	T[Depth].push_back(n);
	if (F.count(n)) return F[n];
	long long k=n/2;
	if (n%2==0) { // n=2*k
		return F[n] = (f(k, Depth+1)*f(k, Depth+1) + f(k-1, Depth+1)*f(k-1, Depth+1)) % M;
	} else { // n=2*k+1
		return F[n] = (f(k, Depth+1)*f(k+1, Depth+1) + f(k-1, Depth+1)*f(k, Depth+1)) % M;
	}
}

int main()
{   
    ibs;cti;
    int t;cin>>t;while(t--){
	long long n;
	F[0]=F[1]=1;
	if (cin >> n) {
		if (n==0) {
			cout << 0 << endl;continue;
		}
		else {
			cout << f(n-1, 0) << endl;continue;
		}
	}
	// for (int i=0; i<1234; i++) if (T[i].size()) {
		// sort(T[0].begin(), T[0].end());
		// T[0].erase(unique(T[0].begin(), T[0].end()), T[0].end());
		// // printf("Depth[%d] : ", i);
		// /*for (int j=0; j<T[i].size(); j++) */printf("%lld ", T[0][0]);
		// printf("\n");
	// }
	}
    return 0;
}