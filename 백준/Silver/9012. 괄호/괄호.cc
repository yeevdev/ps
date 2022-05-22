#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;


bool isVPS(char*);

int main() {
	FASTIO
    
    int T;
    cin >> T;
    
    for(int i = 0; i < T; ++i) {
        string input;
        cin >> input;

        char inputArr[51];
        strcpy(inputArr, input.c_str());

        if(isVPS(inputArr)) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}

bool isVPS(char charArray[]) {
    int pCount = 0;
    for(int i = 0; charArray[i] != '\0'; i++) {
        if(pCount < 0) {
            return false;
        }

        if(charArray[i] == '(') {
            pCount++;
        }
        else if(charArray[i] == ')') {
            pCount--;
        }
    }

    if(pCount == 0) {
        return true;
    }
    else {
        return false;
    }
}
