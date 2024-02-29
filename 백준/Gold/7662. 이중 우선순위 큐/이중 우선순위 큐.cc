#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;


int T;

int main() {
    FASTIO
    
    cin >> T;
    
    for(int i = 0; i < T; i++) {
        int k;
        cin >> k;
        
        multiset<int> ms;
        
        for(int j = 0; j < k; j++) {
            char c;
            int n;
            cin >> c >> n;
            
            if(c == 'I') {
                ms.insert(n);
            }
            else {
                if(ms.empty()) {
                    continue;
                }
                
                if(n == 1) {
                    auto iter = ms.end();
                    iter--;
                    ms.erase(iter);
                }
                else {
                    ms.erase(ms.begin());
                }
            }
        }
        
        if(ms.empty()) {
            cout << "EMPTY" << "\n";
        }
        else {
            auto iter = ms.end();
            iter--;
            cout << *iter << " " << *ms.begin() << "\n";
        }
    }
    
    return 0;
}
