#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;


int main() {
	FASTIO

	int N, K;
	cin >> N >> K;

	vector<int> value;
	for(int i = 0 ; i < N; i++) {
		int input;
		cin >> input;

		value.push_back(input);
	}

	int nowValue = 0;
	int count = 0;
	for(int i = value.size() - 1; i >= 0; i--) {
		if(nowValue == K) {
			break;
		}

		if(value[i] <= K - nowValue) {
			count += (K - nowValue) / value[i];
			nowValue += ((K - nowValue) / value[i]) * value[i];
		}		
	}

	cout << count;

	return 0;
}
