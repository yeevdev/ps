#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;


void BFS();

int M, N, H;
int tomatoBox[101][101][101];  // z, y, x
int visitedCnt[101][101][101];  // 방문 횟수 저장

class Pos {
    public:
    int height, row, column;
    
    public:
    Pos(int height, int row, int column) {
        this->height = height;
        this->row = row;
        this->column = column;
    }
};

deque<Pos> BFSQueue;


void printBox() {
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                cout << tomatoBox[i][j][k] << " ";
            }
            cout << endl;
        }
    }
}


int main() {
    FASTIO
    
    cin >> M >> N >> H;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                cin >> tomatoBox[i][j][k];
            }
        }
    }
    
    // 초기 큐 삽입
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                if(tomatoBox[i][j][k] == 1) {
                    Pos thisPos = Pos(i, j, k);
                    
                    BFSQueue.push_back(thisPos);
                }
            }
        }
    }
    
    BFS();
    
    //printBox();
    
    // 익지 않은 토마토가 있는지 확인
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                if(tomatoBox[i][j][k] == 0) {
                    cout << -1;
                    
                    return 0;  // 프로그램 종료
                }
            }
        }
    }
    
    // 방문 일자 중 최대값 출력
    int ans = -1;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                if(visitedCnt[i][j][k] > ans) {
                    ans = visitedCnt[i][j][k];
                }
            }
        }
    }
    
    cout << ans;
    
    return 0;
}

void BFS() {
    int dHeight[]   = { 1, -1, 0, 0, 0, 0 };
    int dRow[]      = { 0, 0, 0, 0, 1, -1 };
    int dColumn[]   = { 0, 0, 1, -1, 0 ,0 };
    
    while(!BFSQueue.empty()) {
        Pos thisPos = BFSQueue.front();
        
        BFSQueue.pop_front();
        
        for(int i = 0; i < 6; i++) {
            int nHeight = thisPos.height + dHeight[i];
            int nRow = thisPos.row + dRow[i];
            int nColumn = thisPos.column + dColumn[i];
            
            if(nHeight < 0 || nRow < 0 || nColumn < 0 || nHeight > H-1 || nRow > N-1 || nColumn > M-1) {
                continue;
            }
            
            if(tomatoBox[nHeight][nRow][nColumn] == 0) {
                tomatoBox[nHeight][nRow][nColumn] = 1;
                visitedCnt[nHeight][nRow][nColumn] = visitedCnt[thisPos.height][thisPos.row][thisPos.column] + 1;
                
                Pos newPos = Pos(nHeight, nRow, nColumn);
                BFSQueue.push_back(newPos);
            }
        }
    }
    
}
