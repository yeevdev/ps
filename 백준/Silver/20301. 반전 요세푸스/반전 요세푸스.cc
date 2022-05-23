#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;


int main() {
	FASTIO

	int N, K, M;
	cin >> N >> K >> M;

	deque<int> sequence;
	for(int i = 1; i <= N; i++) {
		sequence.push_back(i);
	}

	int count = 0;
	bool check = false;
	while(!sequence.empty()) {
		if(check) {
			for(int i = 0; i < K - 1; i++) {
				sequence.push_front(sequence.back());
				sequence.pop_back();
			}

			cout << sequence.back() << "\n";
			
			sequence.pop_back();
		}
		else {
			for(int i = 0; i < K - 1; i++) {
				sequence.push_back(sequence.front());
				sequence.pop_front();
			}

			cout << sequence.front() << "\n";

			sequence.pop_front();
		}

		count++;
		if(count == M) {
			check = !check;
			count = 0;
		}
	}
}
