#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


using namespace std;

int main() {
	FASTIO

    int N;
    cin >> N;

    int dp[1000001];
    for(auto& element : dp) {
        element = 0;
    }

    for(int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;
        
        if(i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
        if(i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
    }

    cout << dp[N];

	return 0;
}
