#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;


int t;

int main() {
    FASTIO
    
    int n;

    cin >> t;
    while (t--) {
        string order,str;
        bool reverse=false, error=false;
        deque<int> dq;
        cin >> order;
        cin >> n;
        cin >> str;
        string s = "";
        for (int i = 0; i<str.length();i++) {

            if (isdigit(str[i])) {
                s += str[i];

            }
            else {
                if (!s.empty()) {
                    dq.push_back(stoi(s));
                    s = "";
                }
            }
        }
        for (auto o : order) {
            if (o == 'R') {
                if (reverse)
                    reverse = false;
                else
                    reverse = true;
            }
            else {
                if (dq.empty()) {
                    cout << "error" << '\n';
                    error = true;
                    break;
                }
                if (reverse)
                    dq.pop_back();
                else
                    dq.pop_front();
            }
        }
        if (!error) {
            cout << '[';
        }
        if (reverse && !dq.empty()) {
            for (auto o = dq.rbegin(); o != dq.rend(); o++) {
                if (o == dq.rend() - 1)
                    cout << *o;
                else
                cout << *o << ',';
            }
        }
        else if (!reverse&&!dq.empty()){
            for (auto o = dq.begin(); o != dq.end(); o++) {
                if (o == dq.end() - 1)
                    cout << *o;
                else
                cout << *o << ',';
            }
        }
        if(!error)
        cout <<"]\n";

    }
}
