#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9+7;


int main() {
    FASTIO

    int n, m;

    cin >> n >> m;

    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }
    for(int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int result = (dist[i][j] == INF) ? 0 : dist[i][j];
            cout << result << " ";
        }
        cout << "\n";
    }
 
    return 0;
}