#include<bits/stdc++.h>
using namespace std;

//�����Ʒ�
void print_subset(int n,int s) {//��ӡ{0��1��2��3��...��n-1}���Ӽ�s
    for(int i=0;i<n;i++)
        if(s&(1<<i)) printf("%d ",i);//��0ֵ��Ϊ��
    printf("\n");
}

int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<(1<<n);i++) //ö�ٸ��Ӽ�����Ӧ�ı���0��1��2��...��2^n-1
        print_subset(n,i);
    return 0;
}
