#include <bits/stdc++.h>
using namespace std;

int main() {

    int n,m;
    scanf("%d%d",&n,&m);

    vector<int> w;

    for(int i=0;i<n;i++) {
        int tem;
        scanf("%d",&tem);
        w.push_back(tem);
    }


    int ans=0,index=m;//加入新的作业，从m开始
    int tra[100];//最多100个线程并发
    memset(tra,0,sizeof(tra));
    for(int i=0;i<m;i++) {
        tra[i]=w[i];
    }

    int flag = 1;
    while(flag) {
        for(int i=0;i<m;i++) {
            tra[i]--;
            if(tra[i]==0&&index<n) tra[i]=w[index++];//加入新的作业
        }
        ans++;//时间片是1秒

        //判断每个作业是否都完成
        int tem_flag=0;
        for(int i=0;i<m;i++) {
            if(tra[i]!=0) tem_flag=1;
        }
        if(tem_flag==0) flag=0;
    }

    printf("%d\n",ans);

	return 0;
}
/*
5 3
4 4 1 2 1

4
*/
