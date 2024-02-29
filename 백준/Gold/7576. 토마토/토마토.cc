#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;


int M, N;
int tomatoBox[1001][1001];
bool visited[1001][1001];
int path[1001][1001];

int dRow[] = { 0, 0, 1, -1 };
int dColumn[] = { 1, -1, 0, 0 };

deque<pair<int, int>> dayQueue;

void BFS();

void printPath() {
    printf("\n[PATH]\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%2d ", tomatoBox[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    FASTIO
    
    cin >> M >> N;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> tomatoBox[i][j];
        }
    }

    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(tomatoBox[i][j] == 1) {
                dayQueue.push_back(make_pair(i, j));
            }
        }
    }
    
    
    BFS();
    
   // printPath();
    
    // 익은 않은 토마토가 존재한다면 -1 출력
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(tomatoBox[i][j] == 0) {
                cout << -1;
                
                return 0; // 프로그램 종료
            }
        }
    }
    
    // 방문 일자 저장 벡터중 최대값 출력
    int ans = -1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(path[i][j] > ans) {
                ans = path[i][j];
            }
        }
    }
    
    // 정답 출력
    cout << ans;
    
    return 0;
}

void BFS() {
    while(!dayQueue.empty()) {
        int row = dayQueue.front().first;
        int column = dayQueue.front().second;
        tomatoBox[row][column] = 1;
        
        dayQueue.pop_front();
        
        for(int i = 0; i < 4; i++) {
            int nRow = row + dRow[i];
            int nColumn = column + dColumn[i];
            
            if(nRow < 0 || nColumn < 0 || nRow >= N || nColumn >= M) {
                continue; // 박스의 범위를 벗어날 경우
            }
            if(tomatoBox[nRow][nColumn] == 0 && visited[nRow][nColumn] == false) {
                visited[nRow][nColumn] = true;

                dayQueue.push_back(make_pair(nRow, nColumn));

                path[nRow][nColumn] = path[row][column] + 1;
            }
        }
    }
}
