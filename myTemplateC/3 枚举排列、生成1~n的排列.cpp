#include<bits/stdc++.h>
using namespace std;

//ö��1~n������
void print_permutation(int n,int *A,int cur) {
    if(cur==n) {//�ݹ�߽�
        for(int i=0;i<n;i++) printf("%d ",A[i]);
        printf("\n");
    }
    else for(int i=1;i<=n;i++) {//������A[cur]�����������i
        int ok=1;
        for(int j=0;j<cur;j++)
            if(A[j]==i) ok=0;//���i�Ѿ���A[0]~A[cur-1]���ֹ���������ѡ
        if(ok) {
            A[cur]=i;
            print_permutation(n,A,cur+1);//�ݹ����
        }
    }
}

int main() {
    int a[5];
    for(int i=0;i<5;i++) {
        a[i]=i+1;
    }
    print_permutation(5,a,0);
    return 0;
}
