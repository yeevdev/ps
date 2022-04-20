#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;


void backTracking(int, int, vector<int>);

int main() {
	FASTIO

	int N, M;
	cin >> N >> M;

	vector<int> v;
	backTracking(N, M, v);

	return 0;
}

void backTracking(int n, int m, vector<int> v) {
	if(v.size() == m) {
		for(auto& element : v) {
			cout << element << ' ';
		}
		
		cout << '\n';

		return;
	}

	int idx = 0;
	if(v.empty()) {
		idx = 0;
	}
	else {
		idx = v.back();
	}

	for(int i = idx + 1; i <= n; i++) {
		v.push_back(i);
		backTracking(n, m, v);
		v.pop_back();
	}
}