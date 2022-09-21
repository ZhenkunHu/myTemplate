#include<bits/stdc++.h>
using namespace std;

//仿函数、重载()
struct cmp {
    bool operator()(int a,int b) {
        return a<b;
    }
};

int main() {
    priority_queue<int,vector<int>,cmp> que; //定义格式 vector<int> 是规定格式
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
