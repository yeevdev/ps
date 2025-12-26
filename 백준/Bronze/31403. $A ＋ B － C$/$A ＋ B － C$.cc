#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

#include <iostream>
#include <string>
using namespace std;

int main() {
	FASTIO

	int A, B, C;

	// 입력받기
	cin >> A >> B >> C;

	int result1 = A + B - C;

	string strA = to_string(A);
	string strB = to_string(B);
	int result2 = stoi(strA + strB) - C;

	// 출력하기
	cout << result1 << "\n" << result2;

	return 0;
}