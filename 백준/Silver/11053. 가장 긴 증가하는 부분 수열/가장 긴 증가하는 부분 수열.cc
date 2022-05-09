#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


using namespace std;

int main() {
	FASTIO

    int N;
    cin >> N;

    int arr[1001];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int dp[1001];
    for(auto& element : dp) {
        element = 0;
    }

    int result = 0;

    for(int i = 0; i < N; i++) {
        dp[i] = 1;

        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        result = max(result, dp[i]);
    }

    cout << result;

	return 0;
}
