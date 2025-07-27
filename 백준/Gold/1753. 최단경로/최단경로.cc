#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9+7;


int V, E, K;

int main() {
    FASTIO

    cin >> V >> E >> K;

    vector<vector<pii>> adj(V + 1);
    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        pii e = {v, w};

        adj[u].push_back(e);
    }

    vector<int> dist(V + 1, INF);

    priority_queue<pii, vector<pii>, greater<>> pq;
    dist[K] = 0;
    pq.push({0, K});

    while(!pq.empty()) {
        auto [cdist, cur] = pq.top(); pq.pop();
        if(dist[cur] != cdist) continue;
        for(auto [nxt, cost] : adj[cur]) {
            if(dist[nxt] <= dist[cur] + cost) continue;
            pq.push({dist[nxt] = dist[cur]+cost, nxt});
        }
    }

    for(int i = 1; i <= V; i++) {
        int result = dist[i];
        if(result == INF) {
            cout << "INF" << "\n";
        } else {
            cout << result << "\n";
        }
    }

    return 0;
}