#include<bits/stdc++.h>
using namespace std;

//�º���������()
struct cmp {
    bool operator()(int a,int b) {
        return a<b;
    }
};

int main() {
    priority_queue<int,vector<int>,cmp> que; //�����ʽ vector<int> �ǹ涨��ʽ
    que.push(0);
    que.push(1);
    que.push(3);
    que.push(2);
    que.push(4);
    while(!que.empty()) {
        cout<<que.top()<<endl;
        que.pop();
    }
	return 0;
}
