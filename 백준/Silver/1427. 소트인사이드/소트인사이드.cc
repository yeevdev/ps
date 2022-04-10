#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


using namespace std;


int main() {
    FASTIO

    string num;
    cin >> num;

    sort(num.begin(), num.end());
    reverse(num.begin(), num.end());

    cout << num;

    return 0;
}