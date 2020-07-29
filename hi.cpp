#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
// #define N 100010
// ll a[N],b[N],c[N];
string s[22],t[22];
int main()
{
    int n,m;cin>>n>>m;
	for(int i=0; i<n; i++) cin >> s[i];
	for(int i=0; i<m; i++) cin >> t[i];
	int q; cin >> q;
	while(q--){
		int x; cin >> x; x--;
		cout << s[x % n] + t[x % m] << "\n";}
    return 0;   
}