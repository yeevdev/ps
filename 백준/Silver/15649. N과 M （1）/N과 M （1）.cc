#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;


void backTracking(int, int, bool[], vector<int>&);

int main() {
	FASTIO

	int N, M;
	cin >> N >> M;

	//방문여부를 저장하는 bool형 visited 배열과 현재 진행상태를 저장하는 벡터 v를 정의
	bool visited[N + 1] = {false};
	vector<int> v;
	
	backTracking(N, M, visited, v);

	return 0;
}

//백트래킹을 재귀함수로 구현
void backTracking(int n, int m, bool visited[], vector<int>& v) {
	//벡터에 m개의 원소가 담기면 조건을 만족했으므로 출력하고 종료
	if(v.size() == m) {
		for(auto& element : v) {
			cout << element << ' ';
		}

		cout << '\n';

		return;
	}

	//벡터에 m개의 원소가 담기지 않았으므로 m개의 원소가 담길 때까지 재귀
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
