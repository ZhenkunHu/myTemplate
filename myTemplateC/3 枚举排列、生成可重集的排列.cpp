#include<bits/stdc++.h>
using namespace std;

//���ɿ��ؼ�������
void print_permutation(int n,int *A,int *P,int cur) {
    if(cur==n) {//�ݹ�߽�
        for(int i=0;i<n;i++) printf("%d ",A[i]);
        printf("\n");
    }
    else for(int i=0;i<n;i++) if(!i||P[i]!=P[i-1]) {//ö�ٵ��±�Ӧ���ظ�������ΪP�������ź���
        int c1=0,c2=0;
        for(int j=0;j<cur;j++) if(A[j]==P[i]) c1++;
        for(int j=0;j<n;j++) if(P[i]==P[j]) c2++;
        if(c1<c2) {//�ݹ���õ�������ȡ���ˡ���ֹA�����г����ظ����Ľ��������ֹ�����û��ѡ��
            A[cur]=P[i];
            print_permutation(n,A,P,cur+1);//�ݹ����
        }
    }
}

int main() {
    int a[10],p[3];
    for(int i=0;i<3;i++) {
        p[i]=1;
    }
    print_permutation(3,a,p,0);
    return 0;
}
