#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e5+3;
int main()
{   
    ibs;cti;
    int T;cin>>T;
	string s,t;
	while(T--){
		cin>>s>>t;
		set<int>set[150];
		for (int i = 0; i < s.size(); i++)
			set[s[i]].insert(i + 1);
		int ans = 1, cur = 0;
		for (int i = 0; i < t.size();) {
			auto it = set[t[i]].upper_bound(cur);
			if (!cur && it == set[t[i]].end()) {ans = -1; break;}
			else if (it == set[t[i]].end()) cur = 0, ans++;//one  complete search done for s, another one required
			else cur = *it, i++;//t[i] found in s[i],let's check for next element of t
		}
		cout<<ans<<"\n";
	}
    return 0;
}