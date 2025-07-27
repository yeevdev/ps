#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9+7;


int main() {
    FASTIO

    int N, M;
    cin >> N >> M;

    vector<vector<pii>> adj(N+1);

    for(int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        
        pii e = {B, C};
        adj[A].push_back(e);
    }

    vector<ll> dist(N+1, INF);
    dist[1] = 0;

    int nc = 0;
    for(int i = 1; i <= N; i++) {
        for(int cur = 1; cur <= N; cur++) {
            if(dist[cur] == INF) continue;
            for(auto [nxt, cost] : adj[cur]) {
                if(dist[nxt] <= dist[cur] + cost) continue;
                dist[nxt] = dist[cur] + cost;
                if(i == N) nc = 1;
            }
        }
    }

    if(nc == 1) {
        cout << -1 << "\n";
    } else {
        for(int i = 2; i <= N; i++) {
            if(dist[i] == INF) {
                cout << -1 << "\n";
            } else {
                cout << dist[i] << "\n";
            }
        }
    }
 
    return 0;
}