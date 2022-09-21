#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Stu {
    int id, d, c;
} s[100005];

vector<Stu> first, second, third, forth;

bool cmp(Stu l, Stu r) {
    int lt = l.d + l.c, rt = r.d + r.c;
    if(lt != rt) return lt > rt;
    if(l.d != r.d) return l.d > r.d;
    return l.id < r.id;
}

int main() {
    int n, l, h;
    scanf("%d %d %d", &n, &l, &h);
    for(int i = 0; i < n; ++i) {
        int id, de, cai;
        scanf("%d %d %d", &id, &de, &cai);
        s[i].id = id;
        s[i].d = de;
        s[i].c = cai;
    }

    for(int i = 0; i < n; ++i) {//总是用向量整理一遍
        if(s[i].d < l || s[i].c < l) continue;
        if(s[i].d >= h && s[i].c >= h) first.push_back(s[i]);
        else if(s[i].c < h && s[i].d >= h) second.push_back(s[i]);
        else if(s[i].c < h && s[i].d < h && s[i].d >= s[i].c) third.push_back(s[i]);
        else if(s[i].c >= l && s[i].d >= l) forth.push_back(s[i]);
    }

    sort(first.begin(), first.end(), cmp);
    sort(second.begin(), second.end(), cmp);
    sort(third.begin(), third.end(), cmp);
    sort(forth.begin(), forth.end(), cmp);

    cout << first.size() + second.size() + third.size() + forth.size() << endl;
    for(auto s : first) {
        printf("%08d %d %d\n", s.id, s.d, s.c);
    }
    for(auto s : second) {
        printf("%08d %d %d\n", s.id, s.d, s.c);
    }
    for(auto s : third) {
        printf("%08d %d %d\n", s.id, s.d, s.c);
    }
    for(auto s : forth) {
        printf("%08d %d %d\n", s.id, s.d, s.c);
    }

    return 0;
}
