#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


using namespace std;

int fibonacci(int);

int dp[45];

int main() {
	FASTIO

	for(auto& element : dp) {
		element = 0;
	}

	int n;
	cin >> n;

	cout << fibonacci(n);

	return 0;
}

int fibonacci(int n) {
	if(dp[n] > 0) {
		return dp[n];
	}
	else if(n <= 1) {
		return n;
	}
	else {
		dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
		return dp[n];
	}
}
