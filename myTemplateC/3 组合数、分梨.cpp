#include<bits/stdc++.h>
using namespace std;

int c(int m,int n) {
    if(m==0||n==1) return 1;
    if(m>=n) return c(m-n,n)+c(m,n-1); //������������� �������ַַ�����ÿ������һ������Ϊ�պ�ֻ��һ������Ϊ��.
    return c(m,m); //����С������������ʣ�������ȫ��û�ã�ȥ����
}

int main() {
    int n;
    while(cin>>n) {
        int M,N;
        while(n--) {
            cin>>M>>N;
            cout<<c(M,N)<<endl;
        }
    }
    return 0;
}

/*
https://blog.csdn.net/gakki_wpt/article/details/75735946
*/
