#include<bits/stdc++.h>
using namespace std;
int Count=0;//���봫�����Ͷ���ȫ�ֱ���

void check(int n) {
    int i=2;
    int flag=1;

    for(;i*i<=n;i++) {
        if(n%i==0) {
            flag=0;//�ж��Ƿ�������
            while(n%i==0) {//��������i����//�������˳��i����������
                Count++;
                n/=i;
            }
            break;//�������������Ϊ�����Ч�ʣ���Ϊ����������С������
        }
    }

    if(!flag) check(n);//���������������������
    else {
        if(n!=1)//��������������Ҳ�Ϊ1���������ټ�1�������ٳ��Լ�һ�Σ������򲻼ӣ�����ѭ��
            Count++;
        return;
    }
}

int main() {
    int n;
    while(cin>>n) {
        Count=0;
        check(n);
        cout<<Count<<endl;
    }
    return 0;
}

/*
https://blog.csdn.net/qq_39304201/article/details/80024594
*/
