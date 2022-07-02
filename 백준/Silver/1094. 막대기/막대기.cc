#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int getSum(vector<int>);

int main() {
    FASTIO

    //시작
    vector<int> sticks;
    sticks.push_back(64);

    int X;
    cin >> X;

    while(getSum(sticks) != X) {
        int minStickIdx = min_element(sticks.begin(), sticks.end()) - sticks.begin();
        int minStick = sticks[minStickIdx];

        sticks.erase(sticks.begin() + minStickIdx);
        sticks.push_back(minStick / 2);
        sticks.push_back(minStick / 2);

        if(getSum(sticks) - (minStick / 2) >= X) {
            int removeIdx = find(sticks.begin(), sticks.end(), minStick/2) - sticks.begin();
            sticks.erase(sticks.begin() + removeIdx);
        }
    }

    cout << sticks.size();

    return 0;
}

int getSum(vector<int> v) {
    int sum = 0;

    for(auto& num : v) {
        sum += num;
    }

    return sum;
}