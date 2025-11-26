#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;


int main() {
	FASTIO

	int N;
	cin >> N;

	vector<pair<int, int>> v;
	for(int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		
		v.push_back({b, a});
	}

	sort(v.begin(), v.end());

	int before = 0;
	int result = 0;
	for(int i = 0; i < N; i++) {
		if(before <= v[i].second) {
			result++;
			before = v[i].first;
		}
	}

	cout << result;

	return 0;
}
