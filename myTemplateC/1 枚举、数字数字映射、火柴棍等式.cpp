#include <stdio.h>
#include <iostream>
using namespace std;

int f[10]={6,2,5,5,4,5,6,3,7,6};//数字->数字，用数组映射就好

int num(int x) {
    int num=0;
    while(x/10!=0) {//至少有两位数
        num+=f[x%10];
        x/=10;
    }
    num+=f[x];//最后加最大位
    return num;
}

int main() {

    for(int i=0;i<=1111;i++) {
        for(int j=0;j<=1111;j++) {
            if(num(i)+num(j)+num(i+j)==14) {
                //cout<<num(i)<<" "<<num(j)<<" "<<num(i+j)<<" ";
                printf("%d+%d=%d\n",i,j,i+j);
            }
        }
    }

	return 0;
}
/*

*/
