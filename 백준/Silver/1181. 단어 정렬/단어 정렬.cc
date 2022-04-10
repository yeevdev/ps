#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


using namespace std;


bool compare(string& a, string& b);

int main() {
    FASTIO
    
    int N;
    cin >> N;

    vector<string> v;
    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        v.push_back(str);
    }

    sort(v.begin(), v.end(), compare);

    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }

    return 0;
}

bool compare(string& a, string& b) {
    if(a.length() != b.length()) {
        return a.length() < b.length();
    }
    else {
        return a < b;
    }
}