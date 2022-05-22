#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;


int main() {
    FASTIO

    int N, K;
    cin >> N >> K;

    vector<int> sequence;
    vector<int> result;
    for(int i = 1; i <= N; i++) {
        sequence.push_back(i);
    }

    int count = K;
    for(int i = 0; i < N; i++) {
        while(count > sequence.size()) {
            count -= sequence.size();
        }

        result.push_back(sequence[count - 1]);
        sequence.erase(sequence.begin() + count - 1);

        count += K - 1;
    }

    for(int i = 0; i < result.size(); i++) {
        if(result.size() == 1) {
            cout << "<" << result[i] << ">" << "\n";
            break;
        }
        if(i == 0) {
            cout << "<" << result[i] << ", ";
        }
        else if(i == result.size() - 1) {
            cout << result[i] << ">" << "\n";
        }
        else {
            cout << result[i] << ", ";
        }
    }

    return 0;
}
