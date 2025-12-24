#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력용 변수
	int N, T, P;

	// 입력받기
	cin >> N;  // 참가자의 수 N

	vector<int> sizes;
	for(int i = 0; i < 6; i++) {
		int count;
		cin >> count;

		sizes.push_back(count);
	}

	cin >> T >> P;  // 티셔츠 묶음 수, 펜 묶음 수

	int orderTSum = 0;
	for(auto& size : sizes) {
		int count = size / T;
		if((size % T) != 0) {
			count++;
		}
		
		orderTSum += count;
	}

	int orderP1 = N / P;
	int orderP2 = N % P;

	cout << orderTSum << "\n";
	cout << orderP1 << " " << orderP2;

	return 0;
}