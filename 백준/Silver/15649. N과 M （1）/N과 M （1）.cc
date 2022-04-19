#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


using namespace std;


void backTracking(int n, int m, vector<bool>& visited, vector<int>& v);

int main() {
	FASTIO

	int N, M;
	cin >> N >> M;

	vector<bool> visited(N + 1);
	vector<int> v;

	backTracking(N, M, visited, v);


	return 0;
}

void backTracking(int n, int m, vector<bool>& visited, vector<int>& v) {
	if(v.size() == m) {
		for(auto& element : v) {
			cout << element << " ";
		}

		cout << "\n";

		return;
	}

	for(int i = 1; i <= n; i++) {
		if(!visited[i]) {
			visited[i] = true;
			v.push_back(i);
			backTracking(n, m, visited, v);
			visited[i] = false;
			v.pop_back();
		}
	}
}