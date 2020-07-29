#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

set <pair <int, int>> points;

bool under(int x, int y)
{
	auto it = points.lower_bound({ x, 0 });
	return it->second >= y;
}

ll add(int x, int y)
{
	/// I add the rectagle until (x, y)
	auto dr = points.upper_bound({ x, 1e9 });
	auto st = prev(dr);

	ll ans = 0;
	
	/// acum vreau sa scot tot ce e intre st si dr
	while (st->second <= y) {
		/// vreau sa il scot pe it
		ans -= 1LL * (st->first - prev(st)->first) * (st->second - dr->second);
		st = prev(st);
		points.erase(next(st));
	}

	ans += 1LL * (x - st->first) * (y - dr->second);
	points.insert({ x, y });
	return ans;
}

void solve()
{
	int n, c;
	cin >> n >> c;
	vector <ll> ans(c);

	vector <tuple <int, int, int>> input(n);
	for (auto& i : input) {
		cin >> get<0>(i) >> get<1>(i) >> get<2>(i);
		get<2>(i) -= 1;
	}

	reverse(input.begin(), input.end());

	points = { { 0, 2e9 }, { 2e9, 0 } };

	for (auto i : input) {
		if (under(get<0>(i), get<1>(i)))
			continue;
		ans[get<2>(i)] += add(get<0>(i), get<1>(i));
	}

	for (auto i : ans)
		cout << i << ' ';
	cout << '\n';
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}
