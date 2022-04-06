#include <iostream>
#include <vector>

#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


using namespace std;


int main() {
	FASTIO

	int N, M;
	cin >> N >> M;

	vector<int> v(N);
	for(int i = 0; i < N; i++) {
		cin >> v[i];
	}

	int sum = 0;
	int max = 0;
	for(int i = 0; i < v.size() - 2; i++) {
		for(int j = i + 1; j < v.size() - 1; j++) {
			for(int k = j + 1; k < v.size(); k++) {
				sum = v[i] + v[j] + v[k];
                
				if(sum > max && sum <= M) {
					max = sum;
				}
			}
		}
	}

	cout << max;

	return 0;
}
