#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


using namespace std;


class Member {
    public:
    int order;
    int age;
    string name;

    Member(int age, string name) {
        this->age = age;
        this->name = name;
    }
};

bool compareMember(Member& a, Member& b);

int main() {
    FASTIO

    int N;
    cin >> N;

    vector<Member> members;
    for(int i = 0; i < N; i++) {
        int age;
        string name;
        cin >> age >> name;
        
        Member member(age, name);
        member.order = i + 1;

        members.push_back(member);
    }

    sort(members.begin(), members.end(), compareMember);

    for(int i = 0; i < members.size(); i++) {
        cout << members[i].age << " " << members[i].name << "\n";
    }

    return 0;
}

bool compareMember(Member& a, Member& b) {
    if(a.age != b.age) {
        return a.age < b.age;
    }
    else {
        return a.order < b.order;
    }
}