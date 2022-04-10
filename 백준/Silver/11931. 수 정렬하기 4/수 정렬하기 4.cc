#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


using namespace std;


bool compare(int& a, int& b);

int main() {
    FASTIO

    int N;
    cin >> N;

    vector<int> v;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }

    return 0;
}

bool compare(int& a, int& b) {
    if(a > b) {
        return true;
    }
    else {
        return false;
    }
}