#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;


void DFS(int x, int y);

int N;
char colorMap[101][101];
bool isVisited[101][101] = { false };

int main() {
    FASTIO

    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> colorMap[i][j];
        }
    }
    
    // 적록색약이 아닌 사람의 경우
    int amountOfZonesCaseA = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!isVisited[i][j]) {
                DFS(i, j);
                amountOfZonesCaseA++;
            }
        }
    }
    
    // 적록색약이 아닌 사람의 경우
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(colorMap[i][j] == 'G') {
                colorMap[i][j] = 'R';
            }
        }
    }
    
    memset(isVisited, false, sizeof(colorMap));
    
    int amountOfZonesCaseB = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!isVisited[i][j]) {
                DFS(i, j);
                amountOfZonesCaseB++;
            }
        }
    }
    
    cout << amountOfZonesCaseA << " " << amountOfZonesCaseB;
    
    return 0;
}

void DFS(int x, int y) {
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
    
    isVisited[x][y] = true;
    
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || nx >= N || ny < 0 || ny >= N) {
            continue;
        }
        
        if(!isVisited[nx][ny] && (colorMap[x][y] == colorMap[nx][ny])) {
            DFS(nx, ny);
        }
    }
}
